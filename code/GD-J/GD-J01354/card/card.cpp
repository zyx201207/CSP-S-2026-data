#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,k,a[N],b[N],vis[N];
stack<int> c;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=n;j++){
		set<int>s;
		for(int i=j;i<=n;i++){
			if(s.count(a[i])){
				while(c.size()){
					if(c.top()==a[i])break;
					s.erase(c.top());
					c.pop();
				}
			}else{
				c.push(a[i]);
				s.insert(a[i]);
			}
		}
		while(c.size()){
			vis[c.top()]++;
			c.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",vis[i]);
	}
	return 0;
}

