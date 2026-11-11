#include<bits/stdc++.h>
#define int long long

using namespace std;
long long n;
int s;
string a;

string ch;
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> s >> a;
		while(s --){
			ch += a;
		}
	}
	for(int i = 0,j = ch.size() - 1;i <= j;i ++,j --){
		if(ch[i] != ch[j]) cnt ++;
	}
	cout << cnt;
	return 0;
}


/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
