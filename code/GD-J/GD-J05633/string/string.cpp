#include<bits/stdc++.h> 
#define int long long
using namespace std;
signed main(){
	int nn;
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,x=0,xx=0;
    unsigned sum=0;
    char a[1000050];
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
    	int l;
    	scanf("%lld",&l);
    	char b;
    	cin>>b;
    	for(int j=0;j<l;j++){
    		a[x]=b;
    		x++;
		}
	}
	x--;
	int x1=0;
	while(x1<=x){
		if(a[x1]!=a[x]){
        	sum+=1;
		}
		x1++;
		x--;
	}
	cout<<sum;
    
    return 0;
}
