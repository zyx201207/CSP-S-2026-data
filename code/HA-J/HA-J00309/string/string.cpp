#include<bits/stdc++.h>
using namespace std;
string s="";
int x[100005];
char y[100005]; 
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		x[i]==a;
		y[i]==b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	//cout<<s;
	int left=0,right=s.size()-1;
	for(int i=0;i<s.size();i++){
		if(s[left]!=s[right]) cnt++;
		left++;right--;
	}
	cout<<cnt;
	return 0;
}
