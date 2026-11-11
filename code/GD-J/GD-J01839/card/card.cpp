#include <bits/stdc++.h>
using namespace std;
string s = "";
int n,m;
int b[10001];
int cnt;
bool pd(char c){
	for(int i = 0;i < s.size();i++){
		if(c == s[i]){
			cnt = i;
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	char a[10001];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			if(pd(a[j])){
				s += a[j];
			}else{
				string h;
				for(int l = 0;l < cnt;l++){
					h += s[l]; 
				}
				h+=a[j];
				s = h;
			}
		}
		for(int j = 0;j < s.size();j++){
			b[int(s[j]-'0')-1]++;
		}
		s = "";
	}
	for(int i = 0;i < m;i++){
		cout << b[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
