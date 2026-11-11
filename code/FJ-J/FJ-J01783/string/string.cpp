#include<bits/stdc++.h>
using namespace std;
int n,y=0,cnt=0;
string s={};
bool f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int x;
		char a;
		cin>>x>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
		y+=x;
	}
	int z=0;
	if(y%2==0){
		z=y/2;
	}
	else{
		z=(y+1)/2;
	}
	for(int i=0;i<=z;i++){
		if(s[i]!=s[y-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
 
