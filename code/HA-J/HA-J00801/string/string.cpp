#include <bits/stdc++.h>
using namespace std;
int n;  //操作数 
long long l=0;  //字符串总长 
long long num=0;  //更改数 
long long int s1[200001];  //每位字母的数量 
char s2[200001];  //每位字母

char find_n(int x){  //第i位的字母 
	int u=0;
	for (int i=0;i<l;i++){
		u+=s1[i];
		if (u>x) return s2[i];
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		l+=s1[i];
	}
	for (long long i=0;i<l/2;i++){
		if (find_n(i)!=find_n(l-i-1)){
			num++;
		}
	}
	cout<<num;
	return 0;
}
