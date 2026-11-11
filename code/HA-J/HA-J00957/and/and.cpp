#include <bits/stdc++.h>
using namespace std;
int a,b,c,e,f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>a>>b;
    int d[b];
    for(int i=0;i<b;i++)d[i]=-1;
    for(int i=1;i<=a;i++){
    	cin>>c;
    	for(int j=b;j>i;j--){
    		if(c>d[j]){
			    d[j] = c;
    		if(j-1>i)d[j-1]=e;
				e=d[j];
    		}
    	}
    }
    for(int i=1;i<b;i++){
    	f=(d[i]&&d[i-1]);
    	d[i-1]=f;
    }
    cout<<f;
	return 0;
}
