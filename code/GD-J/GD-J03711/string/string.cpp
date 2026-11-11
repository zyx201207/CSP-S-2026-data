#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b,ans1=0,ans2=0;
	int a[200010];
	string s1,s2,s3;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> s1;
		for(int j = 1;j<=a[i];j++){
			s2 += s1;
		}
	}
	for(int i = s2.size()-1;i>=0;i--){
		s3 += s2[i];
	}
	for(int i = 0;i<floor(s2.size()/2);i++){
		if(s3[i]!=s2[i]){
			ans1+=1;
		}
	}
	cout << ans1;
	return 0;
}
