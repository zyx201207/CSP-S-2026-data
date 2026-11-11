#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m,a[N],cnt[N];
int vis[N];
stack <int> s;
int main (){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for (int i=1;i<=n;i++){
		
		for (int i=1;i<=m;i++)vis[i]=0;
		
		for (int j=i;j<=n;j++){
			if (vis[a[j]]==1){
				while (s.size()&&s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
			else {
				s.push(a[j]);
				vis[a[j]]++;
			}
			
		}
		while (s.size()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for (int i=1;i<=m;i++)cout<<cnt[i]<<" ";
		
	return 0;
}
