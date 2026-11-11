#include <bits/stdc++.h>
using namespace std;
int a,c,d,e=0,g=0,k=0;
string h[500000000];
long long b[200000000],f[200000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
    for(int i=0;i<a;i++){
    	cin>>c>>d;
    	for(int j=0;j<c;j++){
    		b[j+e]=d;
    	}
    	e+=c;
    }
    for(int i=0;i<e;i++){
    	f[i]=b[e-i];
    	if(f[i]!=b[i]){
    	    g++;
    	    h[k] = f[i];
    	    for(int j=0;j<k;j++){
    	    	string(f[i]);
    	    	if(h[j]==f[i])
				    g--;
    	    }
        }
        k++;
    }
    cout<<g;
	return 0;
}
