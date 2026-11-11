#include<bits/stdc++.h>
using namespace std;

int n,m,a[99999],b[99999],c[99999];

int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
    cin>>n>>m;
    int w=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	w++;
    	b[w]=a[i];
    	int ss=0;
    	for(int j=1;j<=w;j++){
    		if(ss==1)break;
    		if(b[j]==b[w]){
    			w=j;
    			for(int k=j;k<=w;k++){
    			    b[k]=0;
				}
				for(int k=1;k<=w;k++){
					c[b[i]]++;
					ss=1;
				}
			}
		}
		if(ss==0){
			for(int i=1;i<=w;i++){
				c[b[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
