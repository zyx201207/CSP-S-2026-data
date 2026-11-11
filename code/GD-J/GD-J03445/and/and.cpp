#include<bits/stdc++.h>
using namespace std;
long long int a[200005],d[200005];
bool cmp(int a,int b){
	int m=0,n=0;
	while(a){
	a=a&(a-1);
	m++;	
	}
	while(b){
	b=b&(b-1);
	n++;	
	}
	return m<n;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);	
int m,n;	
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++) cout<<a[i]<<" ";
cout<<endl;


for(int i=1;i<=n-m+1;i++){
for(int j=i;j<=m;j++){
if(d[i]==0) d[i]=a[j];
else d[i]=d[i]&a[j];	
}	
}
int maxn=-999;
for(int i=1;i<=n-m+1;i++){
if(d[i]>maxn) maxn=d[i];
cout<<d[i]<<" ";	
}
cout<<maxn;	

	
	

	
fclose(stdin);
fclose(stdout);		
	
}
