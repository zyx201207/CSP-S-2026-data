#include<bits/stdc++.h>
using namespace std;

long long a[200005];
string c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	string s="";
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s.append(c[i]);
		}
	}
	int cnt=0;
	for(int i=0,j=s.length()-1;i<j;i++,j--){
		if(s[i] != s[j]) cnt++;
	}
	cout << cnt;
	return 0;
}
