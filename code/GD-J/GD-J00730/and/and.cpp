#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
	freopen("ans.out","W",stdout);
    long long n,m;
	long long a[200005],b[20005],ans=0;
	int k=0,k2=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	long long x;
    	cin>>x;
        for(int j=1;j<=31;j++){
        	if(x==pow(2,j)){
        		b[++k2]=x; 
        		break; 
		    }
		}
		a[++k]=x;
	}
	sort(a+1,a+1+k);
	sort(b+1,b+1+k2);
	if(k-m+1<0){
		cout<<b[k2];
	}
	else if(b[k2]>=a[k-m+1]){
		cout<<b[k2];
	}else{
		cout<<a[k-m+1];
	}
	return 0;
} 
