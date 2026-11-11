#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
long long n,m,a[100001],b[10001],g[1001],c=0,d=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int f=1;f<=n;f++){
for(int i=1+c;i<=n;i++){
	b[c+1]=a[i];
	for(int j=i-1;j>=1+d;j--){
		if(a[i]==a[j]){
		for(int z=j;z<i;z++){
			b[z]=0;
		}
		}
	}
	c++;
}
for(int i=1;i<=c;i++){
	g[b[i]]++;
	b[i]=0;
}
d++;
c=d;
}
for(int i=1;i<=m;i++){
cout<<g[i]<<" ";	
}
return 0;
}
