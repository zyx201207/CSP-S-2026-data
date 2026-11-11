#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, aa;
	long long ans=0;
	cin >> n;
	vector<int> a(n);
	vector<char> s(n);
	for (int i=0;i<n;i++){
		cin.ignore();
		cin >> a[i];
		cin.ignore();
		cin >> s[i];
	}
	long long l=0, r=n-1, al=a[0], ar=a[n-1];
	while (l<r){
		if (s[l]==s[r]){
			if (al<ar){
				l++;
				ar-=al;
				al=a[l];
			}else if (al>ar){
				r--;
				al-=ar;
				ar=a[r];
			}else {
				l++;
				r--;
				al=a[l];
				ar=a[r];
			}
		}else{
			if (al<ar){
				l++;
				ar-=al;
				ans+=al;
				al=a[l];
			}else if (al>ar){
				r--;
				al-=ar;
				ans+=ar;
				ar=a[r];
			}else {
				l++;
				r--;
				ans+=al;
				al=a[l];
				ar=a[r];
			}
		}
	}
	cout << ans;
	return 0;
}
