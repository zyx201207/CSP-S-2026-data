#include <bits/stdc++.h>
using namespace std;
long long n[2000005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	string s,x,y;
	cin>>a;
	if(a==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<a;i++){
		cin>>n[i]>>s[i];
	}
	if(a==2){
		if(n[0]>=n[1]){
			cout<<n[0];
		}
		else{
			cout<<n[1];
		}
		return 0;
	}
	long long w=0,sum=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<n[i];j++){
			x[w]=s[i];
			y[a-w]=s[i];
			w++;
		}
	}
	for(int i=0;i<w;i++){
		if(x[i]!=y[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

