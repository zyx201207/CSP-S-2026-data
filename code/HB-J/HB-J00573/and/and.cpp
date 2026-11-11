#include<bits/stdc++.h>
using namespace std;
struct zs{
	long long a;
	int b;
}co[200005];
int no(long long x){
	int sum=0;
	while(x/2!=0){
		 sum+=x%2;
		 x/=2;
	}
	return sum+x;
}
bool cmp(zs x,zs y){
	if(x.b==y.b){
		return x.a>y.a;
	}else{
		return x.b>y.b;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long t;
		cin>>t;
		co[i].a=t;
		co[i].b=no(t);		
	}
	sort(1+zs,n+zs+1,cmp);
	int ans=co[1].a;
	for(int i=2;i<=m;i++){
		int u=co[i].a;	
		ans=ans&u;
	}
	cout<<ans;
}
