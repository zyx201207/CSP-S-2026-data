#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num=0;
	string number;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		num+=x;
		for(int j=1;j<=x;j++){
			number=number+y;
		}
	}
	string str=number;
	int mid;
	if(num%2==1)mid=(num+1)/2;
	else mid=num/2+1;
	int ans=0;
	for(int i=1;i<mid;i++){
		if(str[i-1] != str[num-i])ans++;
	}
	cout<<ans;
	return 0;
}
