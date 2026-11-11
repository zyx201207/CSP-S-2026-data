#include<bits/stdc++.h>
using namespace std;

struct re{
	int numder;
	string English;
};
re a[200005];
long long n;
long long cnt = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string ans;
	for(int i= 1; i<= n; i++){
		cin >> a[i].numder >> a[i].English;
		for(int j = 1; j<=a[i].numder; j++){
			ans += a[i].English;
		}
	}
	for(int i = 0; i<ans.size(); i++){
		int c = ans.size()-i-1;
		if(ans[i] != ans[c]){
			ans[c] = ans[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
