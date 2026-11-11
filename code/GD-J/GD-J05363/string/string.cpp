#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans;
	cin>>n;
	long long c[n+10];
	char d[n+10];
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
        c[i]=a;
        d[i]=b;
	}
	int e=n/2;
	int i=0;
	int j=n-1;
	while(i<j){
		if(d[i]!=d[j]){
		    if(c[i]>=c[j]){
		    	ans+=c[j];
		    	c[i]-=c[j];
		    	j--;
		    }else{
		    	ans+=c[i];
		    	c[j]-=c[i];
		    	i++;
			}
		}else{
			if(c[i]>=c[j]){
		    	c[i]-=c[j];
		    	j--;
		    }else{
		    	c[j]-=c[i];
		    	i++;
			}
		} 
		
	}
	cout<<ans;
	return 0;
}
