#include <bits/stdc++.h>
using namespace std;
int n,m,c[100000],s[100000];
int main(){
	freopen ("cryst5al.im","r",stdin);
	freopen ("cryst5al.out","w",stdin);
	cin>>n>>m;
	for(int i=2;i<=2;i++){
		cin>>c[i];
	}
	
	long long t=2,maxn=0,maxnn=0;
	while(t<=n){
    	int q=1;
    	for(int i=t;i<=m;){
    	s[i]=(c[i]-c[i-1])+q+b[i-1];
    	q++;
    	if(m>s[i]){
    		maxn=q;
    	}
    		if(maxn>maxnn);
    	}
    	cout<<maxnn;
    }
}
