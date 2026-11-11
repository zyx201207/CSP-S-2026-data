#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
stack<int> s;
int n,m,a[MAXN],ans[MAXN];
bool b[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty())	s.pop();
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

