#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char s;
	string str,str1;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		char a;
		cin>>a;
		for(int j = 1;j <= x;j++){
			str += a;
		}
	}
	str1 = str;
	reverse(str1.begin(),str1.end());
	if(str1 == str){
		cout<<0;
		exit(0);
	}
	unsigned long long num = str.size()/2;
	cout<<num;
}


