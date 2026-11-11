#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n ; cin >> n ;
	string m="" ;
	while(n--){
		long long l ; char a ; cin >> l >> a;
		while(l--){
			m += a ;
		}
	}
	long long num{0};
	if(m.size()%2==0){
		string ans = m.substr(0,m.size()/2);
		reverse(ans.begin(),ans.end());
		long long k = 0 ;
		for(long long i = m.size()/2 ; i < m.size() ; i++ ){
			if(m[i]!=ans[k]){
				m[i] = ans[k];
				num++;
			}
			k++;
		}
	}else{
		string ans = m.substr(0,m.size()/2);
		reverse(ans.begin(),ans.end());
		long long k = 0 ;
		for(long long i = m.size()/2+1 ; i < m.size() ; i++ ){
			if(m[i]!=ans[k]){
				m[i] = ans[k];
				num++;
			}
			k++;
		}
	}
	cout << num << endl;
}
