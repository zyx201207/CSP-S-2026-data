#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
bool s[N];
int a[N],n,m,ans[N];
deque<int> d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int x=0;x<d.size();x++){
				if(d[x]==a[j]){
					for(int y=x;y<d.size();y++){
						s[y]=1;
						d.pop_back();
					}
					break;
				}
			}
			d.push_back(j);
		}
		for(int j=0;j<d.size();j++){
			ans[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[a[i]]<<" ";
	}
	return 0;
}
