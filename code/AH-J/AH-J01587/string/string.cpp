#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N],aa;
long long n,b[N],s,o=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>b[i]>>aa;
    	if(b[i]>1000000){
    		int h;
			char hh;
    		for(int i=1;i<n;i++)cin>>h>>hh;
    		cout<<b[i]*n/2;
    		return 0;
		}
        for(int j=o;j<o+b[i];j++){
            a[j]=aa;
      	}
      	o+=b[i];
	}
	o--;
	for(int i=1;i<=o;i++,o--){
    	if(a[i]!=a[o]){
    		s++;
		}
	}
	cout<<s;
	return 0;
}
