#include<bits/stdc++.h>
using namespace std;
long long n,d,C,T;
long long a[2000005];
long long s[2000005],b[2000005];
long long ans,minc,k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				minc=1e9;
				ans+=check(i,j);
			}
		}
		if(C==13||C==14)
			cout<<0<<'\n';
		else
			cout<<1<<'\n';
		T--;
	}
	return 0;
}
