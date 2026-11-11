#include<bits/stdc++.h>
using namespace std;
stack<int>st,s;
int n,m;
int a[500005],h[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=st;
		memset(h,0,sizeof h);
		for(int j=i;j<=n;j++){
			while(h[a[j]]){
				h[s.top()]--;
				s.pop();
			}
			s.push(a[j]);
			h[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=h[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
