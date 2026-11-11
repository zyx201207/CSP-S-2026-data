#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long t[n],g[n],h=0;char m[n],d;
	for(int i=0;i<n;i++){
		cin>>g[i]>>m[i];
		h+=g[i];
		if(d!=m[i]){
			d=m[i];
		}
		t[(int)d]++;
	}
	if(t[(int)d]==n){
		cout<<"0";
		return 0;
	}
	if(h==1){
		cout<<"0";
	}
	cout<<h/2;
    return 0;
}
