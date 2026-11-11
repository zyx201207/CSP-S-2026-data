#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
long long m,a[500005],sum;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum=0;
		flag=true;
		for(t=i-1;t>0;t--){
			sum+=a[i]-a[t];
			if(sum>m){
				flag=false;
				break;
			}
		}
		if(!flag)
			ans=max(ans,i-t);
		else
			ans=max(ans,i);
	}
	cout<<ans<<endl;
	return 0;
}
