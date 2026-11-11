#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
int c,n,m,d,q,minx=INT_MAX,x,y;
int w[505],k[505],a[505][505],t[505][505];
void dfs(int u,int v,int sum){
	if(u==v){
		minx=min(minx,sum);
		return ;
	}
	if(sum>minx){
		return ;
	}
	sum+=w[u];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==u){
				for(int l=1;l<=k[i];l++){
					if(a[i][l]!=u){
						cout<<sum<<endl;
						dfs(a[i][l],v,sum+t[i][l]);
					}
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		minx=0;
		dfs(x,y,0);
		cout<<minx<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n;
bool ok;
string s[10005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	cin>>n;
	//cout<<endl;
	for(int i=0;i<=n;i++){
		getline(cin,s[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<"cout<<";
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='"'){
				if(j!=0){
					cout<<'"'<<"<<"<<"'"<<'"'<<"'"<<"<<";
					ok=0;
				}else{
					cout<<"'"<<'"'<<"'"<<"<<";
					ok=0;
				}
				continue;
			}else if(s[i][j]=='\n'){
				cout<<"endl";
				ok=0;
				continue;
			}else{
				if(ok==0){
					cout<<'"'<<s[i][j];
					ok=1;
				}else{
					cout<<s[i][j];
				}
			}
		}
		if(ok==0){
			cout<<"endl;"<<endl;
		}else{
			cout<<'"'<<"<<endl;"<<endl;
			ok=0;
		}
	}
    return 0;
}
*/
