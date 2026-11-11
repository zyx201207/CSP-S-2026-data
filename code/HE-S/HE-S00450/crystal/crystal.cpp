#include<bits/stdc++.h>
using namespace std;
void bijiao(int a,int b){
	if(b>a){
		swap(a,b);
	}
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=1;
    long long n,m;
    long long a[100005];
    
	cin>>n>>m;
	long long M=m;
	long long i=1,j=1;
	int biao=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//…˝–Ú≈≈–Ú 
	for(i=1;i<=n;i++){
	    for(j=1;j<=1;j++){
	    	bijiao(a[i],a[j]);
		}
	}
	    for(i=1;i<=n-1;i++){
	    	while(a[i]<a[i+1]){
	    	if((biao==0) && (M<=0)){
	    		cout<<ans<<" ";
	    		biao=1;
	    	}
			a[i]=a[i]+1;
			M=M-i;
		}
		ans++;
		}
		if(biao==0){
			cout<<ans;
		}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

