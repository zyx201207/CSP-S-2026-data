#include<bits/stdc++.h>
using namespace std;

long long n,a;
char c;
string s;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	
	int ss=0;
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) ss++;
		l++;r--;
	}
	
	cout<<ss;
	
	return 0;
	
}









