#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		while(x--){
			s+=y;
		}
	}
	long long cnt=0;
	for(long long i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			s[j]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
