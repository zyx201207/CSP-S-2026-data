//GZ-J00668 遵义市新蒲新区滨湖中学 杨一凡
#include<bits/stdc++.h>
using namespace std;
int n , c;
string s;
struct zfc{
	int a;
	char c;
}x[200001];
bool hw(string p){
	bool f = false;
	int m = p.size();
	string p1;
	while(m > 0){
		m--;
		p1 += p[m];
	}
	if(p1 == p) f == true;
	return f;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
    	cin >> x[i].a >> x[i].c;
    	for(int j = 1;j <= x[i].a;j++) s += x[i].c;
	} 
//	cout << s;
	if(hw(s) == true) cout << c;
	else{
		int l = 0 , r = s.size() - 1;
		while(l <= r){
			if(s[l] == s[r]){
				l++;
				r--;
			}else{
				s[r] = s[l];
				c++;
				l++;
				r--;
			}if(hw(s) == true) break;
		}
	}cout << c;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

