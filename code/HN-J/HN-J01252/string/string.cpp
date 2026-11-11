#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,num=0;
	char c;
	cin>>n;
	string s;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (int j=1;j<=a;j++){
			s[num]=c;
			num++;
		}
	}
	long long l=0,r=num-1,ans=0;
	for (int i=0;i<num;i++){
		if(s[l]!=s[r]){
			ans++;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

