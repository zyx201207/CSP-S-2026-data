#include <bits/stdc++.h>
using namespace std;
long long n;
string m,zimu;
int v=0;
long long  shuliang;
int main()
{
	
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int sum=0;
    for(int i=1;i<=n;i++){
		cin>>shuliang>>zimu[i];
		v+=shuliang;
		for(int j=1;j<=shuliang;j++){
		    m+zimu;
	    }
	}
	for(int i=1;i<=v;i++){
		if(m[i]!=m[v]-i+1){
			m[v-i+1]=m[i];
			sum++;
		}
	}
	cout<<"0"<<"/n";
    return 0;
}
