#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
bool ok[200005];
bool a[200005][35];
bool ans[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,w=0;cin>>x;
		while(x){
			a[i][++w]=x%2==1?true:false;
			x/=2;
		}
		ok[i]=true;
	}
	for(int i=31;i>=0;i--){
		int num=0;
		for(int j=1;j<=n;j++){
			if(ok[j]==true&&a[j][i]==true){
				num++;
			}
		}
		if(num>=m){
			ans[i]=true;
			for(int j=1;j<=n;j++){
				if(ok[j]==true&&a[j][i]==false){
					ok[j]=false;
				}
			}
		}
	}
	int pos=0;
	for(int i=1;i<=31;i++){
		if(ans[i])pos=pos+(1<<(i-1));
	}
	cout<<pos<<endl;
	return 0;
}
