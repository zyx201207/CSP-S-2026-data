#include<bits/stdc++.h>
using namespace std;
long long n,x,k,cnt,y;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x >> c;
		for(int i=1;i<=x;i++){
			s[++k]=c;
		}
	}
	for(long long i=1,j=k;i<j;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	cout << cnt;
	return 0;
}

