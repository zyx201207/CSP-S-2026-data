#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
long long a[500001],m,n,maxx=0,cnt,b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
		//cout<<b[i]<<' ';
	}//cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]*(j-i)-(b[j]-b[i]+1)<=m){
				cnt=j-i;
				
			}
		}
		if(cnt>maxx){
			maxx=cnt;
		}
	}
	printf("%lld",maxx);
	return 0;
}
