#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string k;
	long long m=0;
	for(int i=1;i<=n;i++){
		int t;
		char s;	
		cin>>t>>s;
		for(int j=1;j<=t;j++){
			k+=s;
		}
		m+=t;
	}
	long long sum=0;
	long long i=0,j=m-1;
	while(i<j){
		if(k[i]!=k[j]){
			sum++;
		}
		i++,j--;
	}
	cout<<sum;
}
