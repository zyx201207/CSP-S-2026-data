#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool flag=1;
long long s,z,x,tot,d,tot2,w;
long long a[10000000],b[10000000],c[10000000];
int  cry(int y){
	if(y>0){	
	 for(int i=1;i<=n;i++){
	    if(a[s]>a[i])s=i;
	 }
	a[s]=a[s]+1;
	y=y-1;
    cry(y);
    }
    else{
    for(int i=1;i<=n;i++)
	b[i]=a[i];
	for(int i=1;i<=n;i++){
	 for(int j=1;j<=n;j++){
	 if(a[j]==b[i]){
	 	c[i]++;
	  }
     }
   }
    z=c[0];
     for(int i=0;i<n;i++)
     z=max(c[i],z);
     cout<<z;
    }
    
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	d=a[n];
	for(int i=1;i<=n;i++)d=max(a[n],a[i]);
	for(int i=1;i<=n;i++){
	 w=a[1];
	 if(w!=a[i]){
	 	flag=0;
	 	break;
	 }
	}
	for(int i=1;i<=n-1;i++){
	tot=tot+(d-a[i]);
	tot2=tot2+a[i];
	}
	if(m>=tot&&flag==0)cout<<n;
	else if(m>=tot2&&flag==1){
	cout<<n++;
	}
	else if(m<tot2&&flag==1){
	cout<<m;	
	}
	else{
	s=0;
	cry(m);
	}
	return 0;
}
