#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s[100000005];
    int cnt = 0,num,ans=0;
    cin >> num;
    for(int i=1;i<=num;i++){
		int eng;
		cin >> eng;
		char na;
		cin >> na;
		for(int j=0;j<eng;j++){
			s[cnt] = na;
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++){
		 if(s[i]==s[cnt-i]) continue;
		 else ans++;
		}
	cout << ans;
    return 0;
}

