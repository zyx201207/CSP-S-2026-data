#include <bits/stdc++.h>
using namespace std;
int a[999];
int b[999];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
int n,m,z=0,wei,lei=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int j=1;j<=n;j++){
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
	}
}
}

for(int i=1;i<=n-i;i++){
	if(a[i+1]-a[i]<m||a[i+1]-a[i]==m){
	while(a[i]!=a[i+1]){
		a[i]=a[i]+1;
		m=m-1;
	}
}
else{
	i=1;
}
if(m==0){
		break;
	}
}

for(int i=1;i<=n-1;i++){
	
	for(int j=1;j<=n-1;j++){
		if(a[i]==a[j+1]){
			lei=lei+1;
		}
	}
	b[i]=lei;
	lei=0;
}
for(int i=1;i<=n;i++){
	if(z<b[i]){
		z=b[i];
		wei=b[i];
	}
}
cout<<wei+1;
	return 0;
}
