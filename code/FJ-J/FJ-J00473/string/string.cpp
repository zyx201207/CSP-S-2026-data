#include <bits/stdc++.h>
using namespace std;
bool aaa(string h){
	string t = "";
	long long j = 0;
	for(long long i = h.size() - 1;i >= 0;i--){
		t[j] = h[i];
		j++;
	}
	if(t == h){
		return true;
	}else{
		return false;
	}
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt = 0,y = 0;
	string s = "";
	char c;
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a >> c;
		for(long long j = 0;j < a;j++){
			s[y] = c;
			y++;
		}
	}
	long long z = s.size() - 1,x = 0;
	while(!aaa(s)){
		if(s[z] != s[x]){
			s[z] = s[x];
			cnt++;
			x++;
			z--;
		}else{
			x++;
			z--;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
