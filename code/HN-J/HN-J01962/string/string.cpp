#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	string s;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)s+=c;
	}
	long long len=s.length(),ans=0;
	int left=0,right=len-1;
	while(left<right){
		if(s[left]!=s[right])ans++;
		left++;
		right--;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
why
我是谁我是猞窩釋誰 
*/
