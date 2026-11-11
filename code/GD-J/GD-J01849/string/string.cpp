#include<bits/stdc++.h>
using namespace std;
int n,min1=9000000;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		if(a<min1) min1=a;
		if(a!=1) flag=0;
	}
	if(n==1) cout<<0;
	else if(n==2){
		cout<<min1;
	}
	if(flag==1){
		int cnt=0,sum=s.size();
			for(int i=0;i<sum/2;i++){
				if(s[i]!=s[sum-i-1]) cnt++;
			}
		cout<<cnt;
	}            
	return 0;
}
