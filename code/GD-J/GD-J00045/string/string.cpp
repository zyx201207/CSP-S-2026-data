#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,sum,cnt,ans,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(long long i=1,j=n;cnt<sum-1;){
		if(a[j]>=a[i]){
			if(c[j]!=c[i]){
				ans+=a[i];
			}
			cnt+=a[i]+a[i];
			a[j]-=a[i];
			a[i]=0;
			if(a[j]==0)j--;
			i++;
			continue;
		}
		while(a[j]<=a[i]){
			if(c[j]!=c[i]){
				ans+=a[j];
			}
			cnt+=a[j]+a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		if(a[i]==0)i++;
	}
	cout<<ans;
	return 0;
}
