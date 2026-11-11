#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>q;
long long a,ans,b,o,x1[50],y1[50],xn,yn;
int n,m;
long long c(long long d){
	int u=1;
	for(int i=1;i<=d;i++){
		u*=2;
	}
	return u;
}
void and(long long x,long long y){
	while(1){
		xn=0;
		if(c(xn)<=x&&c(xn+1)>x)
			break;
		xn++;
	}
	for(long long i=xn+1;i>=1;i--){
		x1[i]=x%2;
		x/2;
	}
	while(1){
		yn=0;
		if(c(yn)<=y&&c(yn+1)>y)
			break;
		yn++;
	}
	for(long long i=yn+1;i>=1;i--){
		y1[i]=y%2;
		y/2;
	}
	for(int i=max(xn,yn);i>=1;i--){
		if(y1[i]==x1[i]) ans+=c(i);
	}
}  
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a; 
		q.push(a);
	}
	ans=q.top();
	for(int i=1;i<=m;i++){
		q.pop();
		b=ans;
		o=q.top();
		and(b,o);
 	}
 	cout<<ans;
	return 0;
}
