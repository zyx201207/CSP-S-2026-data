#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N];
bool vis[M];
int ans[M];
stack<int> s;
struct node{
	int id,st,lst;
	int ans;
}q[M];
bool cmp1(node A,node B){
	return A.lst>B.lst;
}
bool cmp2(node A,node B){
	return A.id<B.id;
}
priority_queue<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool FA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])FA=0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[a[j]]){
					while(!s.empty()){
						if(s.top()==a[j])break;
						vis[s.top()]=0;
						s.pop();
					}
				}else{
					s.push(a[j]);
					vis[a[j]]=1;
				}
			}for(int j=1;j<=m;j++){
				ans[j]+=vis[j];
				vis[j]=0;
			}
		}for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}if(FA){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(m<=3000){
		for(int i=1;i<=n;i++){
			int c=a[i];
			q[c].id=c;
			q[c].st=q[c].lst;
			q[c].lst=i;
		}
		sort(q+1,q+m+1,cmp1);
		int mx=0;
		for(int i=1;i<=m;i++){
			while(!st.empty() && st.top()>q[i].lst){
				st.pop();
			}
			q[i].ans=q[i].lst-st.top();
			if(q[i].st){
				st.push(q[i].st);
			}
		}
		sort(q+1,q+m+1,cmp2);
		for(int i=1;i<=m;i++){
			cout<<q[i].ans<<" ";
		}
	}
	return 0;
}

