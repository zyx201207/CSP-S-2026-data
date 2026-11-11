#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n,k;
LL sum;
LL a[N],ta[N],len;
char c[N],tc[N];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
   for(int i=1;i<=n/2;i++){
   	char p,p1;
   	LL tmp,x;
   	int dui=n+1-i;
   	    if(!f){
   	    	p=c[dui];
   	    	p1=c[i];
   	    	tmp=a[dui];
   	    	x=a[i];
		  }else{
		  	p=a[i];
		  	p1=a[dui];
		  	tmp=c[i];
		  	x=a[dui];
		  }
		
	for(int j=1;j<=k;j++){
   	   	if(ta[j]!=0){
   	   		 if(tc[j]==p){
   	   	   	if(ta[j]<tmp){
   	   	   		tmp-=ta[j];
   	   	   		ta[j]=0;
				}else{
					tmp=0;
					ta[j]-=tmp;	
					break;			
				}
			}else{
				sum+=min(tmp,ta[j]);
				if(tmp>=ta[j]){
					tmp-=ta[j];
					ta[j]=0;
					
				}else{
					tmp=0;
					ta[j]-=tmp;
					break;
				}
			}
		 }  
	}
	if(p1==p){
		k++;
		ta[k]=abs(tmp-x);
		if(tmp>x){
			if(f) f=0;
			if(!f) f=1;
		}		
	}else{
		if(tmp>x){
			sum+=x;
			if(f) f=0;
			if(!f) f=1;
			k=1;
			ta[k]=tmp-x;
			tc[k]=p;
		}else{
			sum+=tmp;
			ta[++k]=x-tmp;
			tc[k]=p1;
		}
	  }	
   }
   cout<<sum;
   return 0;
}
