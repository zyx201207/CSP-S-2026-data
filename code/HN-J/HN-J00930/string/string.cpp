#include<bits/stdc++.h>
using namespace std;
int n;
long long L,sum=0,a;
string S="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int ai;
		string ci;
		cin>>ai>>ci;
		for(int j=0;j<ai;j++){
			S+=ci;
		}
		L+=ai;
	}
	a=L-1;
	for(int i=0;i<int(L/2);i++){
		if(S[i]!=S[i+a]){
			sum++;
		}
		a-=2;
	}
	cout<<sum;
	return 0;
}
