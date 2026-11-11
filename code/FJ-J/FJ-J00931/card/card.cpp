#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<long long>s;
		map<long long,int>m;
		for(int j=i;j<=n;j++){
			m[a[j]]++;
			if(m[a[j]]==2){
				m[a[j]]=1;
				while(s.top()!=a[j]){
					m[s.top()]--;
					s.pop();
				}
				s.pop();
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
