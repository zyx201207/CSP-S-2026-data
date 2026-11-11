#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool v[300005];
		for(int j=1;j<=m;j++){
			v[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				s.push(a[j]);
				v[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					v[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
