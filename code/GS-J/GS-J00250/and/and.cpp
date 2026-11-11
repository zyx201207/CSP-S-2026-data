#include<bits/stdc++.h>
using namespace std;
 
long long ch[100000],a1[100000];
long long maxn=0;
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	long long w,z,y,x,a,b,c,d,e,f,g,h,j,i,k,l,m,n,o,p,q,r,s,t,u,v;
	cin>>n>>m;

	for(i=0;i<n;i++){
		cin>>a1[i];
		
	}
	for(i=0;i<n;i++){
		if(a1[i]==0){
			for(j=0;j<n;j++){
				maxn=max(a1[j],maxn);
			}
			cout<<maxn-1;
		}
		if(a1[i]==1&&m==2){
			for(j=0;j<n;j++){
				maxn=max(a1[j],maxn);
			}
			cout<<maxn;
		}
	}
	
	
	
	return 0; 
}
