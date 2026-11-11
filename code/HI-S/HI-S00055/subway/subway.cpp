#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q1;
ll a[500020],p[500020],q[500020];
struct node{
	int x,y;
}b[500020];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].x>>b[i].y; 	
	}
	for(int i=1;i<=q1;i++){
		cin>>p[i]>>q[i];	
	}
	return 0;	
}
