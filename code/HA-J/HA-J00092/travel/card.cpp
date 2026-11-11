#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,a[N],ans[N];
bool v[N];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				v[a[j]]=0;
				while(!s.empty()){
					int l=s.top();
					if(l!=a[j])s.pop();
					else break;
				}
			}
			else {
				s.push(a[j]);
				v[a[j]]=1;
			}
		}
		while(!s.empty()){
			int k=s.top();
			s.pop();
			ans[k]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}


