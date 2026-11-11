#include<bits/stdc++.h>
using namespace std;
bool is_huiwen(string ss){
	string temp_s = "";
	for(long long i = ss.size()-1;i >= 0;i--){
		temp_s += ss[i];
	}
	return (ss == temp_s);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q = 0; cin >> q;
	string s = "";
	for(int i = 0;i < q;i++){
		long long t = 0; string w;
		cin >> t >> w;
		for(long long j = 0;j < t;j++){
			s += w;
		}
	}
	if(!is_huiwen(s)){
		long long sum = 0;
		for(long long i = 0;i < (s.size()/2);i++){
			long long back_i = s.size()-i-1;
			if(s[i] != s[back_i]) sum++;
		}
		cout << sum;
	}else{
		cout << "0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
