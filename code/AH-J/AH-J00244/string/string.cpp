#include<bits/stdc++.h>
using namespace std;
int a;
int m;
char n;
string s;
int t;
int sum=0;
int flag=0;
int cnt=0;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>m>>n;
		for(int j=1;j<=m;j++){
			s[sum]=n;
			sum++;
		}
	}
	int l=0,r=sum-1;
	while(true){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
		if(l>=r){
			break;
		}
		
	}
	cout<<cnt;
}
