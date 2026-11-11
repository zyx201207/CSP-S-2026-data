#include<bits/stdc++.h>
using namespace std;
long long int N,x;
string a,b;
char c;
string s;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>x>>c;
		for(int i = 1;i<=x;i++){
			s+=c;
		}
	}
	int len = s.length();
	int mid = (len+1)/2 - 1;
	for(int i = 0;i<=mid;i++){
		a+=s[i];
	}
	reverse(a.begin(),a.end());
	int cnt = 0;
	for(int i = mid;i<len;i++){
	    int	init = i-mid;
	    if(s[i] != a[init]){
	    	cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
