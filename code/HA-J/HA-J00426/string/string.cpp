#include <bits/stdc++.h>

using namespace std;
const long long N=2e14+5;
long long a,b,n=0,ans=0,_min=0;
char c;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	cin >> a;
	while(a--){
		cin >> b >> c;
		for(int i=1;i<=b;i++){
			s[n]=c;
			n++;
		}
	}
	ans=ceil(n/2);
	int l=0,r=n-1;
	n-=1;
	while(n--){
		if(l==ans){
			break;
		}
		if(s[l]!=s[r]){
			c=0;
			_min++;
		}
		l++;
		r--;
	}
	if(c){
		cout << "0";
	}else{
		cout << _min;
	}
	return 0;
}
//Trick||Treat!
