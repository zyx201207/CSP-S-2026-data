#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,s1;
int n[200000],sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i = 1;i <= a;i++){
		cin>>n[i]>>s[i];
		sum += n[i];
	}
	int x = 0;
	for(int i = 1;i <= a;i++){
		for(int j = 1;j <= n[i];j++){
			x++;
			s1[x] = s[i];
		}
	}
	sum = 0;
	for(int i = 1;i <= x;i++){
		if(s1[i] != s1[x - i + 1]) sum++;
	}
	cout<<sum / 2;
	return 0;
}
