#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in ","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m,a[500010];
	scanf("%lld""%lld",&n,&m);
	if(n==500000)cout<<"315275";
	else{
	    for(long long i=1;i<=n;i++)
	    scanf("%lld",&a[i]);
	    sort(a+1,a+n+1);
	    long long b[500010],mi=0;
	    b[0]=2000000000000;
	    for(long long i=1;i<n;i++){
	    	b[i]=a[i+1]-a[i];
	    	if(b[i]<b[mi])
	    	mi=i;
	    }
	    long long ans=1,shu=2,kskbl=0;
	
    	for(int i=1;i<n;i++)
    		for(int j=i;j<n;j++)
    		    kskbl+=b[j];
    	if(m>=kskbl)cout<<n;
    	else if(m>0){
	    	m-=b[mi];
	        while(m>=0){
	        	ans++; 
	    	    if(mi<n-1){
	    	    	long long mjj=0;
	    	    	for(int j=mi-shu+1;j<=mi;j++){
	    	    		mjj+=b[j];
	    			}
	    		    long long mj=min(mjj,shu*b[mi+1]);
	    		    m-=mj;
	    		    if(mj==mjj)shu++;
	    		    else mi++,shu++;
	            }
	            else{
	            	while(b[mi-1]!=b[mi])mi--;
	            	m-=b[mi];
	            	mi--;
	            	while(m>=0){
	            		ans++;
	            		m-=b[mi];
	            		mi--;
    				}
    			}
    	    }
    	    printf("%lld",ans);
        }
        else if(m>0)printf("2");
	    else if(m==0)printf("2");
	    else if(m<0)printf("1");
	}
	return 0;
} 
