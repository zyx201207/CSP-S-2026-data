#include <bits/stdc++.h>
using namespace std;
int n;
long long num,cnt,l;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>c;
		l+=num;
		for(int j=1;j<=num;j++){
			s+=c;
		}
	}
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-1-i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
