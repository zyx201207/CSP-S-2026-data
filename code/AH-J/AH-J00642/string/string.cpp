#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char a;
	int cnt=0,bb;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>bb;
		cin>>a;
		for(int j=1;j<=bb;j++){
			s+=a;
		}
	}
	string s1=s;
	int size=s.size();
	for(int i=0;i<size;i++){
		for(int j=size-1;j>=0;j--){
			if(s[j]!=s1[i]){
				cnt++;
			}
		}
	}
	cout<<cnt/8;
	return 0;
}

