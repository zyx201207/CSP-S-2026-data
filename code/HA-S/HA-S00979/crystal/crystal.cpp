#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=LLONG_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(1){
		long long ma=LLONG_MAX,mi,si;
		sort(a+1,a+n+1);
		int sa=1;
		for(int i=2;i<=n;i++){
		    if((a[i]-a[i-1]<ma)&&(a[i]!=a[i-1])&&(a[i-1]!=a[i-2])){
			    ma=a[i]-a[i-1];
			    mi=i;
		    }
		    if(a[i]-a[i-1]==0){
		    	int k=sa;
		    	if(a[i-2]!=a[i]){
		    		sa=max(sa,2);
		    	}else{
		    		sa++;
		    	}
		    	if(sa>k){
		    		si=i;
		    	}
		    }
	    }
	    //cout<<ma<<" "<<mi<<" "<<sa<<" "<<si<<endl;
	    ans=max(sa,ans);
	    if(sa==1){
	    	if(m-ma>=0){
	    		a[mi-1]=a[mi];
	    		m-=ma;
	    	    ans++;
	    	}else{
	    		cout<<ans;
	    		return 0;
	    	}
	    }else{
	    	long long sum1,sum2;
	    	sum1=sa*(a[si+1]-a[si]);
	    	if(sum1>m){
	    		sum1=m;
	    	}
	    	if(m-ma>=0){
	    		sum2=ma;
	    	}else{
	    		sum2=m;
	    	}
	    	//cout<<sum1<<" "<<sum2<<endl;
	    	if(sum1>sum2){
	    		a[mi-1]=a[mi];
	    		m-=ma;
	    	    ans++;
	    	}else{
	    		long long x=m/(a[si+1]-a[si]);
	    	    if(x>=sa){
	    		    ans+=sa-1;
	    		    m-=(a[si+1]-a[si])*sa;
	    		    for(int i=si;i>si-sa;i--){
	    		        a[i]=a[si+1];
	    	        }
	    	    }else{
	    		    ans+=x-1;
	    		    cout<<ans;
	    		    return 0;
	    	    }
	    	}
	    	
	    }
	    /*for(int i=1;i<=n;i++){
	    	cout<<a[i]<<" ";
	    }*/
	    if(m==0){
	    	cout<<ans;
	    	return 0;
	    }
	    //cout<<endl<<m<<endl;
	}
	return 0;
}
//Oct31==Dec25?
