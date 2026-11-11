#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000010],pre[2000010],sum=0,ans=0,d,n;
void f(long long a,long long b){
	if(a==n){
		if(b<n){
			sum=0;
			ans=b;
		}else if(b==n){
			sum++;
		}
	}
	long long r=0,q=0;
	while(r<=d){
		r+=pre[a];
		a++;
		if(r<=d){
			f(a,b+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0,ans=0;
		cin>>n>>d;
		for(int i=1 ; i<=n ; i++){
			cin>>x[i];
			pre[i]=x[i]-x[i-1];
		}
		for(int i=2 ; i<=n ; i++){
			f(1,0);
		}
		cout<<sum<<endl;
	}
	return 0;
}