#include<bits/stdc++.h>
using namespace std;
long long hq(long long a){
	long long b=a;
	long long ans=0;
	while(b!=0){
		ans=ans+(b%2);
		b/=2;
	}
	return ans;
}
struct cq{
	long long a,b;
}N[300086];
bool cmp(cq a,cq b){
	if(a.b==b.b) return a.a>b.a;
	return a.b>b.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n;cin>>m;
	for(int i=1;i<=n;i++){
		cin>>N[i].a;
		N[i].b=hq(N[i].a);
		
	}
	sort(N+1,N+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<N[i].a<<' '<<N[i].b<<endl;
	long long ans=N[1].a&N[2].a;
	
	for(int i=3;i<=m;i++){
		ans=ans&N[i].a;
	}
	cout<<ans;
	
}
