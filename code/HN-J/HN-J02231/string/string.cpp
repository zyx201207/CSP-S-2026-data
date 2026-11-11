#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++){
		long long x;
		char y;
		cin>>x>>y;
		t+=x;
		if(c[cnt]==y){
			a[cnt]+=x;
			c[cnt]=y;
		}
		else{
			a[++cnt]=x;
			c[cnt]=y;
		}
	}
	long long ans=0;
	int cnt1=1,cnt2=cnt;
	while(t>1&&cnt1<cnt2){
		if(c[cnt1]!=c[cnt2]){
			if(a[cnt1]>a[cnt2]){
				ans+=a[cnt2];
				a[cnt1]-=a[cnt2];
				t-=(a[cnt2]*2);
				cnt2--;
			}
			else if(a[cnt1]<a[cnt2]){
				ans+=a[cnt1];
				a[cnt2]-=a[cnt1];
				t-=(a[cnt1]*2);
				cnt1++;
			}
			else{
				ans+=a[cnt1];
				t-=(a[cnt1]*2);
				cnt1++;
				cnt2--;
			}
		}
		else{
			if(a[cnt1]>a[cnt2]){
				a[cnt1]-=a[cnt2];
				t-=(a[cnt2]*2);
				cnt2--;
			}
			else if(a[cnt1]<a[cnt2]){
				a[cnt2]-=a[cnt1];
				t-=(a[cnt1]*2);
				cnt1++;
			}
			else{
				t-=(a[cnt1]*2);
				cnt1++;
				cnt2--;
			}
		}
	}
	cout<<ans;
	return 0;
}
