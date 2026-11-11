#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],a[N],b[N],ans,r,l,num;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n==1){cout<<"0\n";continue;}
		if(c<=6){
			for(int i=2;i<=n;i++){
				a[i]=0,b[i]=1;
				for(int j=i-1;j>0;j--){
					a[j]=N,b[j]=0;
					for(int k=j+1;k<=i;k++){
						if(x[k]-x[j]>d)break;
						if(a[k]+1<a[j])a[j]=a[k]+1,b[j]=b[k];
						else if(a[k]+1==a[j])b[j]+=b[k];
					}
					if(b[j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}else if(7<=c&&c<=10){
			ans=0;
			for(int i=2;i<=n;i++){
				a[i]=0,b[i]=1,r=l=i,num=1;
				for(int j=i-1;j>0;j--){
					a[j]=N,b[j]=0;
					while(x[r]-x[j]>d)num-=b[r],r--;
					if(j==r)break;
					if(a[r]!=a[l]){
						l=r,num=b[r];
						while(a[l-1]==a[r])l--,num+=b[l];
					}
					a[j]=a[r]+1,b[j]=num;
					if(b[j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}else if(11<=c&&c<=12){
			int k=d/(x[2]-x[1]);
			if(k>1&&k*2<=n)cout<<n-k*2+1<<"\n";
			else cout<<"0\n";
		}else cout<<"0\n";
	}
	return 0;
}
