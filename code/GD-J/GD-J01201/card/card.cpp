#include<iostream>
#include<cstring>
#include<stack>
#include<cstdio>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m;
int a[maxn];
int T[maxm];
bool vis[maxm];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			int idx=a[i];
			if(vis[idx]==0){
				s.push(idx);
				vis[idx]=1;
			}else{
				while(!s.empty()&&s.top()!=idx){
					vis[s.top()]=0;
					s.pop();
				}
			}
//			stack<int>st=s;
//			while(!st.empty()){
//				cout<<st.top()<<' ';
//				st.pop();
//			}
//			cout<<'\n';
		}
		while(!s.empty()){
			T[s.top()]++;
			s.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)cout<<T[i]<<' ';
	return 0;
}
