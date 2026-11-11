#include<bits/stdc++.h>
using namespace std;
string str="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum_len=0;
	while(n--){
		int len;
		char ch;
		cin>>len>>ch;
		sum_len+=len;
		while(len--){
			str+=ch;
		}
	}
	int ans=0;
	for(int i=1;i<=sum_len/2;i++){
		if(str[i]!=str[sum_len+i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
