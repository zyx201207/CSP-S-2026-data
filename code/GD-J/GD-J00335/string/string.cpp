#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int cnt1=1,cnt2=n,ans=0,s=0;
	while(cnt1<cnt2){
		if(a[cnt1]>a[cnt2]){
			if(c[cnt1]==c[cnt2]){
				a[cnt1]-=a[cnt2];
				cnt2--;
			}
			else{
				ans+=a[cnt2];
				a[cnt1]-=a[cnt2];
				cnt2--;
			}
		}else if(a[cnt1]<a[cnt2]){
			if(c[cnt1]==c[cnt2]){
				a[cnt2]-=a[cnt1];
				cnt1++;
			}
			else{
				ans+=a[cnt1];
				a[cnt2]-=a[cnt1];
				cnt1++;
			}
		}else if(a[cnt1]==a[cnt2]){
			if(c[cnt1]==c[cnt2]){
				a[cnt1]-=a[cnt2];
				cnt1++;
				cnt2--;
			}
			else{
				ans+=a[cnt1];
				a[cnt2]-=a[cnt1];
				cnt1++;
				cnt2--;
			}
		}
	}
	cout<<ans;
	return 0;
}
