#include<bits/stdc++.h>
using namespace std;
int n,z=1,maxx=0,v[500001];
long long m,a[500001];
bool xy(){
    for(int i=1;i<=n;i++){
	    if(a[i]!=a[i-1])return 0;	
	}	
	return 1;
}
bool yx(){
    for(int i=3;i<=n;i++){
	    if(a[i]-a[i-1]!=a[i-1]-a[i-2])return 0;	
	}	
	return 1;
}
int ad(long long x){
	long long sum1=0;
    for(int i=1;i<=n;i++){
	    if(v[i]==1)sum1+=abs(x-a[i]);	
	}	
	return sum1;
}
void dfs(int x,int sum){
    if(sum>m){
	    return;
	}	
	if(maxx<x)maxx=x;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
		    dfs(x+1,ad(a[i]));
		    v[i]=0;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(xy()){
	    cout<<n;
	    return 0;	
	}
	if(yx()){
	   for(int i=1;i<n;i++){
		   m-=i*abs(a[2]-a[1]);
		   if(m<0){
			   cout<<i; 
			   return 0;  
		   }else if(m==0){
			   cout<<i+1;
			   return 0;
		   }
	   }
	   if(m-abs(a[2]-a[1])>=0)cout<<m;
	   else cout<<m-1;
	   return 0; 		
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<maxx-1;
    return 0;	
}
