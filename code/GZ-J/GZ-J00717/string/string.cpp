//GZ-J00717 бюН№бз КывужабЇ 
#include <bits/stdc++.h>
using namespace std;

long long n,a,sl,sum=0;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	sl=s.size();
	for(int i=0;i<(sl+1)/2;i++){
		if(s[i]!=s[sl-1-i]) sum++;
	}
	cout<<sum;
	return 0;
}
