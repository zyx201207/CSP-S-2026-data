#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	long long a[n];long long sum=1;bool ba=0;bool bb=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i+1){
			ba=1;
		}
	}
	sort(a,a+n);
	int N=a[1]-a[0];
	if(n==2){

	}else{
		
		for(long long i=2;i<n;i++){
			if(a[i]-a[i-1]!=N){
				bb=1;
			}
		}
	}

	if(ba==0){
		sum=m+1;
	}else if(bb==0){
		sum=m/N+1; 
	}
	else{

	long long j[n];
	for(long long i=0;i<n;i++){
		
		if(i==0){
			j[i]=0;
		}else{
			j[i]=j[i-1]+abs(a[i]-a[i-1]);
		}
		if(j[i]<=m&&i!=0){
			sum=i+1;
		}else if(i!=0){
			long long jj=0;
			while(jj<i){
				if(j[i]-j[jj]<=m){
					sum=max(i-jj,sum);break;
				}
				jj++;
			}	
		}
	}		
	}
	  
	
	cout<<sum; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
