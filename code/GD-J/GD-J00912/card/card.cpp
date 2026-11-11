#include<bits/stdc++.h>
using namespace std;
int n,m,num,ans,a[300010];
struct Int{
	int f,s,nn;
}d[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	cin>>a[i];
	for(int i=1; i<=n; i++){
		if(d[a[i]].s==0)
		d[a[i]].s=i,d[a[i]].nn++;
		else
		d[a[i]].f=i,d[a[i]].nn++;
	}
	for(int i=1; i<m; i++){
		if(d[i].nn%2==0)
		cout<<d[i].f-d[i].s+1<<" ";
		else 
		cout<<n-d[i].f+d[i].s<<" ";
	}
	cout<<n;
	return 0;
} 
