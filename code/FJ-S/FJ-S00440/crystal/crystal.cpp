#include<iostream>
using namespace std;
int n,m,sum;
int a[500001];
int b[500001];
int c1[500001],c2[500001];
int main(){
     freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
     	cin>>a[i];
     }
     for(int j=1;j<=n-1;j++){
       int z=0;
       for(int i=1;i<=n-1;i++){
     	   if(a[i]>a[i+1]){
     	   	  swap(a[i],a[i+1]);
     	   	  z++;
     	   }
       }
       if(z==0){
       	break;
       }
     }
     int k=0;
     sum=a[2]-a[1];
     for(int i=2;i<=n-1;i++){
     	if((a[i+1]-a[i])!=sum){
     		k=1;
     		break;
     	}
     }
     if(k==0){
     	if(m>=sum){
     		k=1;
     	}
     	for(int i=1;i<=n-1;i++){
     	    m-=i*sum;
     	    if(m>=0){
     	       k++;
     	   }else{
     	   	   cout<<k;
     	   	   return 0;
     	   }
	}
}
     sum=0;
     for(int i=2;i<=n;i++){
     	b[i]=a[i]-a[i-1];
     }
     double f=0;
     double c=-100000001;
     for(int i=1;i<=n;i++){
     	int x=1;
     	for(int j=i;j<=x;j++){
     		if(x<=n)  x++;
     		f+=b[j];
     	}
     	f=f/(x-i+1);
     	if(c<=f){
     		c=f;
     		c1[i]=i,c2[i]=x;
     	}
     }
     fclose(stdin);
     fclose(stdout);
     return 0;
}
