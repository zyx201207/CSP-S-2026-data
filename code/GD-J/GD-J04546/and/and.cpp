#include<bits/stdc++.h>
using namespace std;
int a[20005];
int b[20005][100000];
int t[20005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i];
	}
	int maxn=0;
    for(int i=1;i<=n;i++){
    	int o=0;
    	int y=a[i];
    	while(y>0){
    		int p=1;
    		for(int i=1;i<=o;i++){
    			p*=2;
			}
    		b[i][o+1]=(y%2)*p;
    		y/=2;
    		o++;
		}
		maxn=max(o,maxn);
}
    int lans=0;
	for(int j=1;j<=n;j++){
		int ans=0;
	   	for(int k=j+1;k<=n;k++){
	   		for(int i=maxn+1;i>=1;i++){
	    	    if(b[j][i]==b[k][i]){
	   		    	ans+=b[j][i];
		    	}
		}
		lans=max(ans,lans);
	}
}
    cout<<lans;
    return 0;
}
