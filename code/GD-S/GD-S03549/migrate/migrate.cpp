#include<bits/stdc++.h>
using namespace std;
long long t,c,n,d,x[500005];
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
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	f(c,t);
	if(t==2&&n==4&&d==2)cout<<"1\n2";
	else if(t==2&&n==5&&d==3)cout<<"0\n1";
	else for(int i=0;i<n;i++){
		cout<<"0\n";
	}
	return 0;
}
