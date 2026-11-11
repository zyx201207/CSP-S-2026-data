#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
int n,m,a[N],ans[N];
bool vis[N];
stack<int> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)  cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n])  ans[a[i]]++;
			else{
				ans[a[i]]++;
				ans[a[n]]++;
			}
		}
		for(int i=1;i<=m;i++)  cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!s.empty()&&s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!s.empty()){
			if(vis[s.top()]){
				ans[s.top()]++;
				vis[s.top()]=0;
			}
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)  cout<<ans[i]<<" "; 
	return 0;
}

