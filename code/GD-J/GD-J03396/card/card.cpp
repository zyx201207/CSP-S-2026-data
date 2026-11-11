#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			for(int k=i;k<j;k++){
				if (a[k]==a[j]){
					s.pop();
					while (s.top()!=a[j]){
						s.pop();
					}
					s.push(a[j]);
					k=j;
				}
			}
		}
		for(int j=1;j<=s.size();j++){
			cout<<s.top()<<" ";
			d[s.top()]++;
			s.pop();
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}
