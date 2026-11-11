#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s = "";
	long long sum = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		sum += a[i];
		int len = s.size();
		for(int j = len;j < len + a[i];j++){
			s += c[i];
		}
	}
	if(sum % 2 == 1){
		int mid =  sum / 2 + 1,cnt1 = 0,cnt2 = 0;
		for(int i = 0;i < mid;i++){
			if(s[i] != s[n - i]) cnt1++;
		}
		for(int i = mid + 1;i < sum;i++){
			if(s[i] != s[n - i]) cnt2++;
		}
		cout << min(cnt1,cnt2) << endl; 
	}else{
		int mid = sum / 2,cnt1 = 0,cnt2 = 0;
		for(int i = 0;i < mid;i++){
			if(s[i] != s[n - i]) cnt1++;
		}
		for(int i = mid + 1;i < sum;i++){
			if(s[i] != s[n - i]) cnt2++;
		}
		cout << min(cnt1,cnt2) << endl; 
	}
	return 0;
}
