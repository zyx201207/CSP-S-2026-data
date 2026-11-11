#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin >> n;
	for (int i = 1 ; i <= n ; i ++){
		long long t;
		char a;
		cin >> t >> a;
		for (long long j = 0 ; j < t ; j ++){
			s+=a;
		}
	}
	string r=s;
	reverse(r.begin(),r.end());
	if(r==s){
		cout << 0;
	}else{
		long long cnt=0,len=s.size();
		for (int i = 0 ; i < len ; i ++){
			if(r[i]!=s[i]){
				cnt++;
			}
		}
		cout << cnt/2;
	}
	return 0;
} 
