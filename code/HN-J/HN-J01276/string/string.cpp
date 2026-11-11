#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	long long sum=0;
	while(n--){
		long long i;
		char ch;
		cin>>i>>ch;
		
		for(int k=1;k<=i;k++){
			s[sum+k]=ch;
		}
		sum+=i;
	}
	int cnt=0;
	for(int l=1,r=sum;l<r;l++,r--){
		if(s[l]!=s[r])cnt++;
	}
	cout<<cnt;
	return 0;
}

