#include<bits/stdc++.h>
using namespace std;
long long m,n,d,b=1,p,q;
long long a[500010];
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(b==1){
		b=0;
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				int c;
				c=a[i];
				a[i]=a[i+1];
				a[i+1]=c;
				b=1;
			}
		}
	}
	for(int i=n;i>1;i--){
		p=0;
		q=0;
		q=m;
		for(int l=n;l>=1;l--){
			for(int j=0;j<=q;j++){
		    	if(a[l-1]+j==a[i]){
			    	p++;
			    	q-=j;
			    }
	    	}
	    	if(q<=0) break;
		}
		if(d<p) d=p;
	}
	cout<<d;
	return 0;
}
