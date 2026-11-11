#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],f[500005],g=0;
int n,m;
int abc(int c){
	int d=500005,e=0;
	for(int i=1;i<n;i++){
        if(b[i]<d){
        	d=b[i];
        	e=i;
		}
	}
	if(m>=d){
	    a[e]=a[e]+d;
	    c=c-d;
	    return c;
    }
    else{
    	return 0;
    }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	while(m!=0){
		for(int i=n;i>1;i--){
		    b[i-1]=a[i]-a[i-1];
	    }
		m=abc(m);
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]==a[j]){
				f[i]=f[j]+1;
				f[j]=f[j]+1;
			}
		}
		g=max(g,f[i]);
	}
	cout <<g;
	return 0;
}
