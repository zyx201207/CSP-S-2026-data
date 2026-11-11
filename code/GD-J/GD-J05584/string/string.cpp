#include <bits/stdc++.h> 
using namespace std;

int main() {
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	char a;
	string s1="",s2="";
	int n,l=0;
	cin >> n;
	int m1[n+1]={0},m2[n+1]={0},sum1=0,sum2=0;
	for (int i = 0;i < n;i++) {
		cin >> m1[i] >> a;
		s1 += a;
	} 
	for (int i = n-1;i >= 0;i--) {
		s2 += s1[i];
		m2[l] = m1[i];
		l++;
	}
	if (s1.length() % 2 == 0) l = s1.length()/2;
	else l = s1.length()/2+1;
	for (int i = l;i < s1.length();i++) {
		sum1 += m1[i];
		sum2 += m2[i];
	}
	cout << abs(sum1 - sum2);
	

	return 0;
}
