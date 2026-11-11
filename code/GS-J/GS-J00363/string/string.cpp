#include<bits/stdc++.h>
using namespace std;
//int a[100000005];
//char c[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,st;
	int n,sum=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		ans+=a;
		while(a--){
			s[sum]=c;
			sum++;
		}
	}
	cout<<0;
	return 0;
}
