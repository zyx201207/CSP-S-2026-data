#include <bits/stdc++.h>
using namespace std;

bool cmp1(string a, string b){
//	if (a.size()!=b.size())return a.size()>b.size();
//	for (int i=0;i<min(a.size(), b.size());i++){
//		if (a[i]!=b[i])return a[i]>b[i];
//	}
	int a1=0, b1=0;
	for (int i=0;i<a.size();i++){
		if (a[i]=='1')a1++;
	}
	for (int i=0;i<b.size();i++){
		if (b[i]=='1')b1++;
	}
	if (a1!=b1)return a1>b1;
	return a>b;
//	return a.size()>b.size();
}
bool cmp2(string a, string b){
	if (a.size()!=b.size())return a.size()>b.size();
	for (int i=0;i<min(a.size(), b.size());i++){
		if (a[i]!=b[i])return a[i]>b[i];
	}
}
string to2(int n){
	string s;
	while (n>0){
		s+=char(n%2+'0');
		n/=2;
	}
	reverse(s.begin(), s.end());
	for (int i=0;i<30-s.size();i++)s='0'+s;
	return s;
}

int to10(string s){
	int n=0;
	for (int i=0;i<s.size();i++){
		n+=(s[i]-'0')*pow(2, s.size()-1-i);
	}
	return n;
}

string nums[200001];
int num[200001];
int main(){
	int n, m, cn, ans=0b111111111111111111111111111111, maxnnn=0;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> cn;
		if (cn>maxnnn)maxnnn=cn;
		nums[i]=to2(cn);
	}
	if (maxnnn==n-1)sort(nums, nums+n, cmp2);
	else sort(nums, nums+n, cmp1);
	for (int i=0;i<n;i++){
		num[i]=to10(nums[i]);
	}
	for (int i=0;i<m;i++){
		ans &= num[i];
	} 
	cout << ans;
	return 0;
}
