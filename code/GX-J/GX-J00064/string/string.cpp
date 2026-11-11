#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			l++;
		}
	}
	long long cnt=0;
	for(long long i=0;i<=(l/2)-1;i++){
		if(s[i]!=s[l-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
