#include<bits/stdc++.h>
using namespace std;
	string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0;
	char b;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	int y=s.size()-1,x=0;
	while(y-x>=0){
		if(s[x]!=s[y]){
			sum++;
		}
		x++;
		y--;
	}
	cout << sum;
	return 0;
}
