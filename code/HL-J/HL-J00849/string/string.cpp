#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	string str=" ";
	int len=1;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		len+=a;
		char c;cin>>c;
		for(int j=1;j<=a;j++)str+=c;
	}
	//i->1
	//j->len
//	cout<<len;
	int i=1,j=len-1;
	int cnt=0;
	while(i<j){
		if(str[i]!=str[j]){
			str[j]=str[i];
			cnt++;
		}
		i++,j--;
	}
//	for(int i=1;i<=len;i++)cout<<str[i];
	cout<<cnt;
	/*
	3
	2 a
	2 b
	1 c

	2
	2 a
	3 a

	6
	1000000000 a
	1000000000 a
	1000000000 a
	1000000000 b
	1000000000 b
	1000000000 b
	*/
	return 0;
}