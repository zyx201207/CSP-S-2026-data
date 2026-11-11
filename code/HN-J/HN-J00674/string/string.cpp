#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,cnt=0;
	string s;
	char a;
	int a1;
	for(int i=1;i<=n;i++){
		cin>>a1>>a;
		sum+=a1;
		while(a1--){
			s+=a;
		}
	}
	for(int i=0;i<=(sum-1)/2;i++){
		if(s[i]!=s[sum-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
	
}
