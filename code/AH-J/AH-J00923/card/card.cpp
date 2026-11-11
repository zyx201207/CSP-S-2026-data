#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,f=0,h;
int a[N],b[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		if(a[j]==a[i]){
			h=j; 
		}
	}
	for(int j=h;j<=n;j++){
		b[a[j]]++;
	}
}
for(int i=1;i<=m;i++){
	printf("%d ",b[i]);
}
return 0;
}

