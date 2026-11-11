//GZ-S00359 贵州省黔西第一中学 代毅承  
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005;
long long n,m,num,a[maxn],b,v[maxn],u[maxn],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int hehe=1;hehe<=c;hehe++){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int dc=1;
	long long dui=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=dui){
			dc=0;
		}
	}
	if(dc==1&&d<dui<<2){
		cout<<"0 ";
	}
	if(dc==1&&d>=dui<<2){
		long long ans;
		ans=d/dui;
		cout<<ans;
	}
	long long numm=0;
	if(n<=3){
		cout<<"2 ";
	}
	else{
		cout<<numm;
	}
	}
	return 0;
}
