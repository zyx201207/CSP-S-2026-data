#include<bits/stdc++.h>
using namespace std;
long long int n,m,k;
long long int a[100010],b[100010];
long long int q[100010],d[100010];

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=m;i>=1;i--){
	b[i]=a[i];
	
	int pp=1;
	while(b[i]!=0){
		if(b[i]%2==0){
			b[i]=0;
		}
		else{
			b[i]=1;
			}
			b[i]/=2;
		pp++;
	}d[i]=pp;
	k=max(d[i],k);
}
cout<<k+10;
return 0;
}

