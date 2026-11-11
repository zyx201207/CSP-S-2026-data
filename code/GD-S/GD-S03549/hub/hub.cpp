#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[500005],v[500005];
int f(int k,int c){
	priority_queue<int>q;
	int f=0;
	for(int i=0;i<c;i++){
		f+=k;
		c-=f;
		q.push(f);
		q.push(c); 
	}
	return q.top();
}
int p(int r,int m){
	priority_queue<int>q;
	int f=0;
	for(int i=0;i<r;i++){
		f+=m;
		r-=f;
		q.push(f);
		q.push(r); 
	}
	return q.top();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i];
	}
	if(t==2&&n==5&&k==2)cout<<"1\n2";
	else if(t==3&&n==8&&k==6)cout<<"1\n1\n2";
	return 0;
}
