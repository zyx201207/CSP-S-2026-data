#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[105];
	string s[105];
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]==s[0]){
			cout<<"0";
			break;
		}else if(s[i]!=s[i-1]){
			cnt+=a[i];
		}
		cout<<cnt;
	}
	return 0;
}
