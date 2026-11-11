#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1000;
const int M=3*1e5+1000;

int n,m;
int num[N];
int vis[M];
int cnt[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int k=1;k<=n;k++){
		stack<int> st;	
		for(int i=k;i<=n;i++){			
			int x=num[i];
			if(vis[x]){
				while(!st.empty()){
					int y=st.top();
					st.pop();
					vis[y]=0;
					if(x==y) break;
				}
			}
			st.push(x);vis[x]=1;
		}
//		cout<<"term: "<<k<<" st: ";
		while(!st.empty()){
			int y=st.top();
			st.pop();
			vis[y]=0;
			cnt[y]++;
//			cout<<y<<" ";
		}
//		cout<<endl;
	}
	
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

