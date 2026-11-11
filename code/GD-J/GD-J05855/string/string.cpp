#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c;
	long long x,k,q=0,t=0,y[10000000];
	cin>>x;
	for(long long i=0;i<x;i++){
		cin>>k>>c;
		for(long long j=0;j<k;j++){
			y[q]=c[0]-'a';
			q++;
		}
	}
	long long i=1;
	while(i<=q-i){
			if(y[i-1]!=y[q-i]){
			t++;
		}
		i++;
	}
	
	cout<<t;
	
	
	
	return 0;
}
