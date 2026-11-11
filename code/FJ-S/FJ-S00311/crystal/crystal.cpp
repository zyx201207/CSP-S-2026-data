#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>=i;j--){
			for(int k=1;k<=j;k++){
				d[i-n+1]+=b[j-k+1]*k;
			}
	    }
    }
    
    for(int i=n;i>=1;i--){
    	if(m>=c[i])
    	{
    		cout<<i;
    		break;
		}
	}
	return 0;
}
