#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001],c[1000001]={0},n,w=1,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		w=i;
		for(int j=i;j<=n;j++){
		b[w]=a[j];
		for(int k=i;k<=w;k++){
		    if(b[k]==b[w]){
		    	w=k;
		    	break;
			}
	    }
	    }
	    for(int j=i;j<=n;j++){
		    c[b[j]]++;
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
