#include<bits/stdc++.h>
using namespace std;
int n,m,a[5600000],b[5600000]={0},k=1,c[6000000]={0},o=1;
void ot(int l){
	for(int i=l;i<=n;i++){
		    for(int j=1;j<=k;j++){
			    if(b[j]==a[i]){
				    for(int h=j;h<=k;h++){
					    b[h]=0;
					    k=j;
				    }
				    break;
			    }
		    }
		    b[k]=a[i];
		    k++;
	    }
}
void op(int g,int f){
	for(int i=1;i<g;i++){
	    	for(int j=1;j<=f;j++){
	    		if(b[i]==j){
	    			c[j]++;
				}
			}
		}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(o<=n){
		k=1;
		ot(o);
		op(k,m);
	    o++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
