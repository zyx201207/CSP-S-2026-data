#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],tong[300010],q[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	stack<int>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			tong[a[j]]++;
			if(tong[a[j]]==2){
				while(s.top()!=a[j]){
					tong[s.top()]--;
					s.pop();
				}
				s.pop();
				tong[a[j]]=1;
			}
			s.push(a[j]);
		}
		while(s.size()>0){
			q[s.top()]++;
			tong[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<q[i]<<" ";
	}
	return 0;
}
