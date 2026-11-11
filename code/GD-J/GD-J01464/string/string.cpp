#include <bits/stdc++.h>
using namespace std;
int num[200002];
char str[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long tt = 0;
	for (int i=1; i <= n; i++){
		cin >> num[i] >> str[i];
		tt += num[i];
	}
	int f = 1,l=n,ans = 0,rst = 0;
	if(tt%2==0){
		ans = tt/2;
		cout << ans;
		return 0;
	}
	if (n%2!=0){
		while(true){
		if(f==l){
			ans+=max(num[f],num[l])-min(num[f],num[l])+rst;
			break;
		}
		else if (str[f] != str[l]) {
			ans += max(num[f],num[l])-min(num[f],num[l])+rst;
			rst = max(num[f],num[l])-ans;
			f++;
			l--;
		}
		else{
			rst = max(num[f],num[l])-min(num[f],num[l]);
			f++;
			l--;
		}
		}
		cout << ans;
	}
	else{
		while(true){
		if(f+1==l){
			ans+=max(num[f],num[l])-min(num[f],num[l])+rst;
			break;
		}
		else if (str[f] != str[l]) {
			ans += max(num[f],num[l])-min(num[f],num[l])+rst;
			rst = max(num[f],num[l])-ans;
			f++;
			l--;
		}
		else{
			rst = max(num[f],num[l])-min(num[f],num[l]);
			f++;
			l--;
		}
		}
		cout << ans;
	}
	return 0;
}
