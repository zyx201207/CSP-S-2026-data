#include<bits/stdc++.h>
using namespace std;
long long const A=500001;
long long a[A]={};
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		bool f=true;
		for(long long j=1;j<=n-i;j++){
			if(a[j]>a[j+1]){
				f=false;
				swap(a[j],a[j+1]);
			}
		}
		if(f==true){
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		if(abs(a[i-1]-a[i])>abs(a[i+1]-a[i])&&m-abs(a[i+1]-a[i])>=0){
			a[i]+=abs(a[i+1]-a[i]);
			m-=abs(a[i+1]-a[i]);
			sum++;
	    }
		else{
		    if(abs(a[i-1]-a[i])<abs(a[i+1]-a[i])&&m-abs(a[i-1]-a[i])>=0){
			    a[i]+=abs(a[i-1]-a[i]);
			    m-=abs(a[i-1]-a[i]);
			    sum++;
		    }
		    else{
		    	if(a[i]==a[i+1]){
		    		sum++;
				}
				else{
					if(a[i]==a[i-1]){
						sum++;
					} 
				}
			}
	    }
    }
	cout<<sum+1;
	return 0;
}
