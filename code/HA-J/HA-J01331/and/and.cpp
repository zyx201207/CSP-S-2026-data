#include  <bits/stdc++.h>
using namespace  std;
int er(int x,int y){
	int a[35],b[35],c[35];
	long long t=0;
	int ix=0,iy=0;
	while (x>0){
		a[ix]=x%2;
		x=x/2;
		ix++;
	}
	while (y>0){
		b[iy]=y%2;
		y=y/2;
		iy++;
	}int k=1;
	for(int i=0;i<max(ix,iy);i++){
	if(a[i]==b[i]){
		t=t+a[i]*k;
	}else{
		t=t+0*k;
	}
	k=k*2;	
	}
	return t;
}
int main( ){
	freopen (and.in,"r",stdin);
freopen (and.out,"w",stdout);
    int n,m;
    cin>>n>>m;
    int zlx[n+5];
    for(int i=1;i<=n;i++){
    	cin>>zlx[i];
    }
    int t=1,s1,s2,p=1,g,max;
   while(m>1){
   	m--;
   	max=0;
   	if(t==1){
   		for(int i=1;i<=n;i++){
   		for(int j=i+1;j<=n;j++){
   			if(max<er(zlx[i],zlx[j])){
   				max=er(zlx[i],zlx[j]);
   				s1=i;
   				s2=j;
   				g=max;
   			}
   		}	
   		}
   		t=0;
   	}else{
   		zlx[s1]=0;zlx[s2]=0;zlx[n+p]=max;
   		max=0;p++;
   		for(int i=1;i<=n;i++){
   		for(int j=i+1;j<=n;j++){
   			if(max<er(zlx[i],zlx[j])){
   				max=er(zlx[i],zlx[j]);
   				s1=i;
   				s2=j;
   				g=max;
   			}
   		}	
   		}
   		
   	}
   }
   cout<<g;
	return 0;
}
