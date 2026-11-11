#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200000],b,maxx; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool c=1;
		for(int j=1;j<=n-1;j++){
	    	if(a[i]>a[i+1]){
		    	swap(a[i],a[i+1]);
		    	c=0;
		    }
    	}
    	if(c){
    		break;
		}
	} 
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		b=a[1];
		for(int i=2;i<=n;i++){
			b=b and a[i];
		}
		cout<<b;
	}
	else if(m==2){
		maxx=-1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				b= a[i] and a[j];
				if(maxx<b){
					maxx=b;
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
