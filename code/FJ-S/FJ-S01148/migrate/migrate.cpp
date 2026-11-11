#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=25000010;
int c,t,n;
long long d,sk[N],ans;
int h[N];
int sum,s;
inline void dfs(int x,int kl,int am)
{
	if(s>2){
		return;
	}
	if(x==am){
		if(sum==0){
			sum=kl;
			s=1;
		}
		else if(kl==sum){
			s++;
		}
		return;
	}
	for(int i=min(h[x],am);i>x;i--){
		dfs(i,kl+1,am);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++){
			cin>>sk[i];
			for(int j=i-1;j>=1;j--){
				if(sk[i]-sk[j]<=d){
					h[j]=i;
				}
				else{
					break;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;
				s=0;
				dfs(i,0,j);
				if(s==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
