#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1],ans[n+1]={0};
	stack<long long> s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s.push(a[i]);
		b[a[i]]++;
		if(b[a[i]]==2){
			s.pop();
			b[a[i]]--;
			while(s.top()!=a[i]){
				s.pop();
				b[s.top()]--;
			}
		}
	} 
	stack<long long> ss=s;
	while(ss.size()){
		ans[ss.top()]++;
		ss.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
