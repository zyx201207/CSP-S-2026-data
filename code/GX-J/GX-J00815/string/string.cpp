#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long lenn,le,conc=0;
	string ai;
	string a,b;
	cin>>lenn;
	for(long long i=0;i<lenn;i++){
        cin>>le>>ai;
        for(long long j=0;j<le;j++){
            a+=ai;
        }
	}
	for(long long i=0;i<a.length()/2;i++){
        if(a[i]!=a[a.length()-i-1]){
            conc+=1;
        }
	}
	cout<<conc;
    return 0;
}
