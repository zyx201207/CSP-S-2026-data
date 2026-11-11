#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],ans=0,q=0;
void as(int b, int c, int d){
	for(int i=d;i<n;i++){if(b==1)c=a[i]&a[i+1];
		c=a[i]&c;ans=max(ans,c);
		if(b<m)as(b+1,c,d+1);else return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];q=max(q,a[i]);}
	as(1,0,1);
	if (m==1)ans=q;
	cout<<ans;
	return 0;
	
}
