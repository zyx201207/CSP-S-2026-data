#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n;
long long sum=0;
long long ans;
char a1[200005],a[200005];
int  b1[200005],b[200005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char> s;
	s.push_back(' ');
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s.push_back(y);
		}
		sum+=x;
	}
	long long d=ceil(sum*1.0/2);
	for(int i=1;i<=d;i++){
		if(s[i]!=s[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c  
*/
