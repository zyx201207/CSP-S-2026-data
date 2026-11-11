#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0,z=0;
	char c[200000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c[i];
		if(c[i]==c[i+1]){
			sum++;
		}
		else{
			z+=a;
		}
	}
	if(sum==n){
		cout<<0;
	}
	else{
		cout<<z-1;
	}
	return 0;
}
