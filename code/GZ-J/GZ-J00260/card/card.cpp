//贵阳市南明区李端棻中学 刘锦阳 GZ-J00260
#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001],card[500001];
int main(){
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> card[i];
	for(int i = 1;i <= n;i++){
		string s;
		for(int j = i;j <= n;j++){
			int flag = -1;
			s.push_back((char)card[j]);
			for(int k = 2;k <= s.size();k++){
				if((int)s[k] == card[j]){
					flag = k;
					break;
				}
			}
			if(flag != -1){
				for(int k = flag;k <= s.size();k++) s.pop_back();
			}
			else s.push_back((char)card[j]);
		}
		for(int i = 0;i <= s.size();i++){
			cout << (int)s[i] << " ";
			a[(int)s[i]]++;
		}
	}
	for(int i = 1;i <= m;i++) cout << a[i] << " ";
	return 0;
}
