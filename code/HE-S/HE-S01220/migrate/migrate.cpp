#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d,p[5],ans=0;
bool a[2000005];
vector <int> path[2000005];
int len[2000005];
void dg(int x,int deep){
	if(x==n){
		return ;
	}
	for(int i=x+1;i<=x+d;i++){
		if(a[i]){
			dg(i,deep+1);
			if(len[i]>deep+1){
				path[x][i]=1;
				len[x]=deep+1;
			}
			else if(len[i]==deep+1){
				path[x][i]++;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			ans=0;
			int x;
			cin>>x;
			a[x]=true;
			dg(1,1);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(path[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
