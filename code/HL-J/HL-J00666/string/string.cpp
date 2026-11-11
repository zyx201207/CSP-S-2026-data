#include<bits/stdc++.h>
using namespace std;
string S[1000000];
char c[10000];
long long n,i,sum=0,a[10000],L=0,outcome=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for (int j=0;j<i;j++){
			sum++;
			S[sum]=c[i];
		}	
	}
	for (int i=0;i<n;i++){
		L+=a[i];
	}
	for (int i=0;i<L/2+1;i++){
		if (S[L-i]!=S[i]){
			outcome++;
		}
	}
	cout<<outcome;
} 
