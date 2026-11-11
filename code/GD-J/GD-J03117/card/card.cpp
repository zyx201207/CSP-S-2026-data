#include<bits/stdc++.h>
using namespace std;
int n,m,s,l,a[500009],c[500009],b[300009],ans[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		stack<int>p;
		l=0;
		for(int j=1;j<=m;j++)b[j]=-1;
		for(int j=0;j<n;j++)c[j]=0;
		for(int j=i;j<n;j++){
			if(b[a[j]]!=-1){
				while(p.top()!=a[j]){
					b[p.top()]=-1;
					p.pop();
				}
			}
			else{
				b[a[j]]=j;
				p.push(a[j]);
			}
		}
		while(!p.empty()){
			ans[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}

