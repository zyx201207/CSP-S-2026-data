#include<bits/stdc++.h>;
using namespace std;
const int N = 1e8;
int n,t = 1,num = 0,sum = 0,m;
int a[N];
char b[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
		num += a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			s[t] = b[i];
			t++;
		} 
	}
	m = num;
	for(int i = 1;i <= num;i++){
		if(s[i] == s[m]){
			m--;
			continue;
		}
		else{
			s[m] = s[i];
			sum++;
			m--;
		}
	}
	cout<<sum;
	return 0;
}
