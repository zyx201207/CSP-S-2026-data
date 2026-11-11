#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		int b = a + sum;
		for(int j=sum;j<=b;j++){
			s[j] == c;
		}
		sum += a;
	}
	int l=0,r=s.size();
	int b=s.size();
	for(int i = 1;i <=b/2;i++){
		if(l == r) break;
		if(s[l] == s[r]){
			l++;
			r--;
		}
		else if(s[l] != s[r]){
			s[l] = s[r];
			l++;
			r--;
		}
	}
	return 0;
}
