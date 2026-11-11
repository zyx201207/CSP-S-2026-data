#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	int sum=0,mid;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		sum += a[i];		//总字符数量 
		for(int j=0;j<a[i];j++){
			s += c[i];		//拼接字符 
			//cout << s << endl; 
		}
	}
	if(sum%2==0){			//取中间数 
		mid = sum/2;
	}
	else{
		mid = (sum-1)/2+1;
	}
	//cout << mid << endl;
	int r = sum-1; 
	int ans=0;
	for(int l=0;l<=sum/2;l++,r--){
		if(s[l]!=s[r]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
