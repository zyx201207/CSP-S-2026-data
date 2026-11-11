#include<bits/stdc++.h>
using namespace std;
long long a[2000000],b[2000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
	    for(int j=sum;j<=n;j++){
	    	for(int r=i+1;r<=n;r++){
	    		if(a[r]==a[i]){
	    			x=r;
	    			break;
				}
			}
		}
		for(int r=x;r<=n;r++){
		    if(r==i){
		    	b[i]++;
		    	break;
			}
		}
		sum++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}