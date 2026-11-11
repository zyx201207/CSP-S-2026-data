#include<bits/stdc++.h>
using namespace std;
int main {
freopen{"string.in",'r',stdin};                                                                                                                                                                          
freopen{"string.out",'w',stdout};
	long long n,a[1000000005];                                                                                                                                                                        
	string c[1000000005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			cin>>c[j];
	    }
	}
	int w=0;
	for(int i=1;i<n;i++){
		w=w+a[i];
	}
	int sum=0;
	if(w%2==0){
		for(int i=1;i<w/2;i++){
				if(a[i]==a[w-i+1]){
					sum=sum;
				}else{
				    sum+=1;
				}
		}
	}else{
		for(int i=1;i<(w-1)/2;i++){
				if(a[i]==a[w-i+1]){
					sum=sum;
				}else{
				    sum+=1;
				}
		}
	}
	cout<<sum;	
    return 0;
}
