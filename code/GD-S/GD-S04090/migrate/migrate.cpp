#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long int x[100001],an[1000001],k[100001],sss=0;
int ys(int,int,int),ug(int,int,int,int);
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int c,t,n,d;
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int sz=0,mx=0,w,bs;
		if(n>=4){
		for(int i=1;i<=n-3;i++){
			for(int u=i+3;u<=n;u++){
			if(d<x[u]-x[i]){
				w=i;
				int p=i+1;
			while(w<u){
			if(w+d>=x[p]&&w+d<x[p+1]){
				mx++;
				w=p;
			}	
			p++;
			}
			//cout<<ys(i,u,mx)<<" ";
			if(ys(i,u,mx)==2){
				sz++;
			}sss=0;
				
			}	
			}
		}	an[o]=sz;
		}
		else{
			an[o]=0;
		}
		
	}
	for(int i=1;i<=t;i++){
		cout<<an[i]<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
int ys(int i,int u,int mx){
int g=mx-1,s=0;
k[0]=i;
sss=0;
ug(i+1,u-1,0,g);
return sss;	
}//
int ug(int a,int b,int d,int g){//cout<<a<<" "<<b<<" ";
if(d==g){
int bl=1;
for(int i=1;i<=g+1;i++){
	if(x[k[i]]-x[k[i]-1]>d){
		bl=0;
	}
}	
if(bl=1){
sss++;	//0 1 5 2 1 2 3 4 5
}
}
else{
for(int i=a;i<=b;i++){
k[d]=a;ug(a+1,b,d+1,g);
}		
}
return 0;
}
