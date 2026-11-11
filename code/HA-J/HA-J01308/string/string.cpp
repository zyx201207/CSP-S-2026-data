#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char S[100000];
	int j=0,sum=0,sum1=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(;j<sum+a;j++){
			S[j]=c;
		}
		sum=j;
	}
	for(int i=0;i<sum/2;i++){
		if(S[i]!=S[sum-i-1]){
			sum1++;
		}
	}
	cout<<sum1;
	return 0;
}
