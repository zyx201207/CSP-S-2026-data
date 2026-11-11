#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5; 
int n,m;
int a[N];
int cnt[N];
bool flag[N];
stack<int> g;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
//	int s=time(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(flag[a[j]]==false){
				flag[a[j]]=true;
				g.push(a[j]);
			}
			else{
				while(!g.empty()&&g.top()!=a[j]){
					flag[g.top()]=false;
					g.pop();
				}
			}
		}
		while(!g.empty()){
			++cnt[g.top()];
			flag[g.top()]=false;
//			cout<<g.top()<<' ';
			g.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;++i){
		cout<<cnt[i]<<' '; 
	}
//	cout<<endl<<time(0)-s;
 return 0;
} 

