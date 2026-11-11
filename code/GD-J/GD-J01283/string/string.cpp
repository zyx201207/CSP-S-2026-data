#include<iostream>
#include<string>
using namespace std;
long long n;
long long a[200010];
char c[200010];
string s;
long long f(){
	long long cnt = 0;
	for(int L = 0, R = s.size()-1; L <= R; L++,R--){
		if(s[L] != s[R]) cnt++;
	}
	return cnt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
		for(int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	cout<<f()<<endl;
	return 0;
}
