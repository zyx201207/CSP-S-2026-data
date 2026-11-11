#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int m,n;
int a[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		stack <int> s;
		bool vis[N]={0};
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				while(s.size()){
					if(s.top()==a[i]) break;
					s.pop();
				}
			}else{
				vis[a[i]]=1;
				s.push(a[i]);
			}
		}
		while(s.size()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" "; 
	return 0;
}

