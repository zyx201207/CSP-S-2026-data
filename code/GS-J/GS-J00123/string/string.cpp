#include<iostream>
#include<cstdio>
#include<cstring>
int main {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	int S[n];
	int a,b,c;
	int sum = n/2;
	cin>>n>>a>>b>>c;
	for(int i=0;i<=a-1;i++){
		cin>>S[i];
	}
	for(int j=a;j<=a+b-1;j++){
		cin>>S[j];
	}
	for(int k=b;k<=b+c-1;k++){
		cin>>S[k];
	}
	for(int q=0;q<=n/2;q++){
		if(S[q]==S[n-q]){
			sum-=1;
		}
	}
	cout<<sum;
	return 0;
}
