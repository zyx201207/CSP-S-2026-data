#include<bits/stdc++.h>
using namespace std;
struct node{
	char m,n;
	long long a,b,c;
};
long long adj[1000000];
node adv[100000];
bool cpu(long long x,long long y){
	return x>y;
}
int main(){
	long long a,b,c,i,j,m,n,k,x,y,z;
	char t;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(i=0;i<a;i++){
		cin>>adj[i];
	} 
	sort(adj+0,adj+a,cpu);
	x=0;
	for(j=0;j<a;j++){
	c=adj[j]; 
	for(i=j+1;i<a;i++){
		c=(c&adj[i]);
	} 
	x=max(c,x);
}
	cout<<c;
	
	return 0;
} 
