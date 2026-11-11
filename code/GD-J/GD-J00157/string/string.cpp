#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char c;
	string h;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a;
		cin >> c;
		for(long long j = 0;j < a;j++)h += c;
	}
	long long l = 0,r = h.length()-1;
	long long sum = 0;
	while(l < r){
		if(h[l] != h[r])sum++;
		l++;
		r--;
	}
	cout << sum;
	return 0;
}
