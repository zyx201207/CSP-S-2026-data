#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) f[i]=abs(a[i]-a[i-1]);
	//cout<<endl;
	for(int i=1;i<=n;i++){
		sum[i]=1;
		long long t=m;
		long long num=0;
		for(int j=i;j>1;j--){
			num+=f[j];
			if(t>=num){
			   sum[i]+=1;
			   t-=num;
			}
			else{
				break;
			}
		}
		//cout<<t;
		//cout<<sum[i]<<endl;
		maxx=max(sum[i],maxx);
	}
	cout<<maxx;
	return 0;
}
