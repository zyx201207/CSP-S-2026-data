#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],mp[2000005],b[2000005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(s.top()!=a[j]&&s.size()){
					mp[s.top()]--;
					s.pop();
				}
				s.pop();
			}
			mp[a[j]]=1;s.push(a[j]);
		}
		while(s.size()){
			b[s.top()]++;
			s.pop();
		}
		for(int i=1;i<=m;i++)mp[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
}
