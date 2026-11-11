#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],desk[100005],n1=0;
int n2[100005]={0};
bool b[100005]={0};
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++){
    	memset(b,0,n);
    	for(int j=i;j<=n;j++){
    	    for(int c=1;c<=n1;c++){
    	    	if(a[j]==desk[c]){
    	    		for(int d=c;d<=n1;d++)
	                    b[d]=1;
    	    		b[j]=1;
					n1=c-1;
					break;
				}
			}
			if(b[j]==0){
				n1++;
				desk[n1]=a[j];
				n2[a[j]]++;
				b[j]=1;
				break;
			}	
		}
	}
	for(int i=1;i<=m;i++){
		int b1=0;
		for(int j=i+1;j<=m;j++){
			if(i==j)
			b1++;
		}
		if(b1==0)cout<<n2[i]<<' ';
	}
	return 0;
}
