#include<bits/stdc++.h>
using namespace std;
int n,x,cnt,num;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s=s+c;
			num++;
		}
	}
	for(int i=(num+1)/2;i<num;i++){
		if(s[num-i-1]!=s[i]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
