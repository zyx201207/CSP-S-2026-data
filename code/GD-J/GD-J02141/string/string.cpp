#include<bits/stdc++.h>
using namespace std;
string s;
int n,x;
char z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int t=1;t<=n;t++){
		cin>>x>>z;
		for(int i=1;i<=x;i++){
			s+=z;
		}
	}
	int a=s.size();
	int y=s.size()-1,cnt=0,cntn=0;
	for(int i=1;i<=a/2;i++){
		if(s[cnt]!=s[y]) cntn++;
		cnt++;
		y--;
	}
	cout<<cntn;
	return 0;
}
