#include <iostream>
#include <cstring>
#include <stack>
#define long long ll
using namespace std;
stack<int> s;
int n,m,a[500005],ans[500005],l,vc,vv[500005];
bool vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			if(!vis[a[j]]) {
				vis[a[j]]=true;
				vv[++vc]=a[j];
			}
			else {
				vis[a[j]]=false;
				while(s.top()!=a[j]&&!s.empty()) {
					s.pop();
				}
				if(s.top()==a[j]) {
					s.pop();
				}
			}
			s.push(a[j]);
		}
		while(!s.empty()) {
			ans[s.top()]++;
			s.pop();
		}
		for(int j=1;j<=vc;j++) {
			vis[vv[j]]=false;
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
