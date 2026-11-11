#include <bits/stdc++.h>
using namespace std;
string s;
long long n,m,j = 1,num,sum;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>m>>c;
		num+=m;
		for(int k = 1;k <= m;k++){
			s += c;
		}
	}
	num = num/2-1;
	for(int i = 0;i <= num;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
