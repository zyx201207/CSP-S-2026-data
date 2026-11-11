#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,int> ans;
stack<int> s;
bool t[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++)
			t[k]=0;
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				s.push(a[j]);
				t[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					t[s.top()]=0;
					s.pop();
				}
			}
		}
		while(s.size()>0){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
