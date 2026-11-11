#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num,cnt = 0;
    int a[100005];
    char b[200005];
    string s;
    cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			s+=b[i];
		}
	}
	num = s.length();
	for(int i = 0;i <= num;i++){
		if(s[i] != s[num-i-1]){
			s[i] = s[num-i-1];
			cnt++;
		}

	}
    //fclose("string.in");
    //fclose("string.out");
    cout << cnt;
    return 0;
}
