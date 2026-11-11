#include<bits/stdc++.h>
using namespace std;
int n,m,p=pow(2,31)-1,h,o=0,maxn=0;
int num(int x){
	int y=0;
	while(x>0)y+=(x%2),x/=2;
	return y;	
}
int a[200010],b[200010];
bool cmp(int x,int y){
	return (x&o)>(y&o);
}
bool cmp2(int x,int y){
	if(num(x&o)==num(y&o))return x>y;
		return num(x&o)>num(y&o);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
}
   if(n<=20){
	   for(int i=1;i<=n;i++){
		   for(int j=1;j<=20;j++)b[j]=a[j]; 
		   o=b[i];
		   b[i]=0;
		   for(int j=2;j<=m;j++){
		   sort(b+1,b+n+1,cmp);	
		   o=o&b[1];	
		   b[1]=0; 
		   }
         maxn=max(maxn,o);
	   }
	   cout<<maxn<<endl;
   }
   else{
	   if(m==n){
		   o=a[1];
		   for(int i=2;i<=n;i++)o=o&a[i];
		   cout<<o;
	   }
	   else if(m==1){
		   o=a[1];
		   for(int i=2;i<=n;i++)o=max(o,a[i]);
		   cout<<o;
	   }
	   else if(m==2){
		   o=0;
		   for(int i=1;i<n;i++){
			   for(int j=i+1;j<=n;j++){
				   o=max(o,a[i]&a[j]);
			   }
	   }
	cout<<o;  
 
}
 else if(m==n-1){
		   for(int i=1;i<=n;i++){
			   for(int j=1;j<=n;j++){
				   if(j!=i)o=o&a[i];
			   }
			   maxn=max(maxn,o);
		   }
		   cout<<maxn;
	   }
	   else{
		   o=pow(2,31)-1;
		   sort(a+1,a+n+1,cmp);
		   cout<<a[m]<<endl;
	   }
}
    return 0;
}
