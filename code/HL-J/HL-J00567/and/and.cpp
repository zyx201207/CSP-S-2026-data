#include<bits/stdc++.h>
using namespace std;
int s[200100];
int kkk(int a,int b){
	string c = "";
	string x = "",y = "";
	int cnt = 0;
	while(a){
		x += char((a%2)+'0');
		a /= 2;
	}
	while(b){
		y += char((b%2)+'0');
		b /= 2;
	}
	while(x.size() != y.size()){
		if(x.size() < y.size()){
			x += "0";
		}else{
			y += "0";
		}
	}
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	int len = min(x.size(),y.size());
	for(int i = 0;i < len;i++){
		if(x[i] == y[i] && x[i] == '1') c +="1";
		else c += "0";
	}
	reverse(c.begin(),c.end());
	int u = 1;
	for(int i = 0;i < c.size();i++){
		cnt += u*(int)(c[i]-'0');
		u *= 2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j<=n;j++){
			if(i != j){
				cnt = max(cnt,kkk(s[i],s[j]));
			}	
		}
	}
	cout << cnt;
	return 0;
}
