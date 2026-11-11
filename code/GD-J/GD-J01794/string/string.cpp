#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a;
int A(){
	int len=a.size();
	int ans=0;
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1]){
			ans++;
			a[len-i-1]=a[i];
		}
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	while(n--){
		int p;
		char s;
		cin>>p>>s;
		for(int j=1;j<=p;j++){
			a+=s;
		}
	}
	cout<<A()<<endl;
	//cout<<a;
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
*/

