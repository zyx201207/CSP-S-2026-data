#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005];
bool f=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]) f=1;
    }
    if(f){
        for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		b[a[j]]++;
		}
	    }
	    for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	    }	
	}else{
		cout<<n;
	}
	return 0;
}
