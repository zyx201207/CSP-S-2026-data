#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100],a1[100];
int zhi1,zhi2,x=1,x1;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w".stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}

	for(int i=1;x1<=n-m;x1++,i++){
zhi2=a[a1[1]];
for(int j=1;j<=m;j++){
	a1[j]=j+i-1;
}
int t=0;

for(;x+t<=n-2;){
zhi2=a[i];

		for(;x<=m-t;++x){				
		zhi2=zhi2&a[a1[x+t]];	
		}		
		if(zhi1<zhi2){
			zhi1=zhi2;
		}		
		x=i;
		++t;		
	}		
	}
	cout<<zhi1;
	return 0;
}
