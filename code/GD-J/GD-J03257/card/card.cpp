#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
int ans[1000000];
int v[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int lll=1;lll<=n;lll++){
		stack<int> s;
		for(int i=lll;i<=n;i++){
			if(v[a[i]]==1){
				while(s.top()!=a[i]){
					v[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[i]);
				v[a[i]]=1;
			}
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//¹À·Ö:?
