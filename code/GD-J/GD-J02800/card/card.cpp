#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005]={0},c[10000005]={0},d[1000005]={0},s=1;
int main(){
freopen("card.txt","r",stdin);
freopen("card.txt","w",stdout);
cin>>n>>m;	
for(int i=1;i<=n;i++){
	cin>>a[i];
}
int z=0;
for(int i=1;i<=n;i++){
	z=0;
	s=1;
	for(int y=i;y<=n;y++){
	if(c[a[y]]==0) c[a[y]]++;
	else{
		c[a[y]]++;
		for(int j=s;j<y;j++){
			if(a[j]==a[y]){
				z=1;
			}
			if(z==1) c[a[j]]--;
		}
		s=y;
	}
}
for(int i=1;i<=m;i++){
	cout<<c[i]<<" ";
if(c[i]>0) d[i]++;
c[i]=0;
}
}
for(int i=1;i<=m;i++){
	cout<<d[i]<<" ";
}
	return 0;
}
