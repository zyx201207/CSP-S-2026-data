#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[30]={0},sum=0,sum1=10000000009;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int b;
	char c;
	for(int i=0;i<n;i++){
		cin>>b>>c;
		a[c-97]+=b;
	}
	int cnt=0;
	for(int i=0;i<26;i++){
		if(a[i]==0){
			cnt++;
		}
		if(a[i]>sum){
			sum=a[i];
		}
		if(a[i]<sum1){
			sum1=a[i];
		}
	}
	if(cnt==25){
		cout<<0;
	}else{
		cout<<sum-sum1;
	}
	return 0;
}
