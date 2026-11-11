//GZ-J00616 观山湖中学 张皓宇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	int n,a,b,v=0;
	string s="";
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	if(s.size()%2==1){
		for(int i=1;i<=(s.size()-1)/2;i++){
			if(s[i]!=s[s.size()-i+1]) v++;
		}
	}
	else if(s.size()%2==0){
		for(int i=1;i<=s.size()/2;i++){
			if(s[i]!=s[s.size()-i+1]) v++;
		}
	}
	cout << v;
}
