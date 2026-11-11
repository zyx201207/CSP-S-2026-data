#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=5e5+5;
int n,m,a[N];
int ans[N];
int stk[N],tp=0;
bool instk[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tp=0;
		for(int j=i;j<=n;j++){
			if(instk[a[j]]){
				while(stk[tp]!=a[j]){
					instk[stk[tp]]=false;
					tp--;
				}
				tp--;
			}
			stk[++tp]=a[j];
			instk[a[j]]=true;
		}
		for(int i=1;i<=m;i++){
			if(instk[i]){
				ans[i]++;
				instk[i]=false;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "[i==m];
	}
	return 0;
}

