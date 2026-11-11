#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,k,b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i;i<=n;i++){
		if(a[i]!=0){
		    b[i]+=a[i];	
		}
		for(int z=1;z<=i;z++){
			if(a[i]==a[z]){
				a[z]==0;
		    for(int j=i-1;j>=1;j--){
		    	b[j]=0;
		        }	
	 	    }
	    }
	    c[i]+=1;
	}
	for(int i=1;i<=n;i++){
		cout<<c[i];
			}
	return 0;
}
