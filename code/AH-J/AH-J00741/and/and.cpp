#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k=0,e[100000000],a[100000000],maxx=-1,o;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    		if(i+m-1<=n){
    			k=a[i];
    	for(int j=i+1;j<=i+m-1;j++){
    		k=k&a[j];
		}
		o++;
		e[o]=k;
		k=0;
		}
		else{
			k=a[i];
			for(int j=i+1;j<=n;j++){
				k=k&a[j];
			}
			for(int j=1;j<=i+m-n-1;j++){
				k=k&a[j];
			}
		o++;
		e[o]=k;
		k=0;
		}
	}
	for(int i=1;i<=o;i++){
		if(e[i]>maxx){
			maxx=e[i];
		}
	}
	cout<<maxx;
    return 0;
}
