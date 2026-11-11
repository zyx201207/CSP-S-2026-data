#include <bits/stdc++.h>
using namespace std;
stack<long long>a;
long long n,m,s[300010],b[500010],ss[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	for(long long i=1;i<=n;i++){
		if(s[b[i]]==1){
			a.pop();
			while(a.top()!=s[b[i]]){
				s[a.top()]=0;
				a.pop();
			}
		}
		else{
			s[b[i]]=1;
			a.push(b[i]);
		}
		while(a.empty()!=0){
			ss[a.top()]++;
			a.pop();
			s[a.top()]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ss[i]<<' ';
	}
	return 0;
}
