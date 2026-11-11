#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,num,ct;
struct node{
	int ge;
	char c;
};
node a[N];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].ge>>a[i].c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].ge;j++){
			s+=a[i].c;
			num++;
		}
	}
	int mid;
	if(num%2==1) mid=num/2+1;
	else mid=num/2;
	for(int i=1;i<=mid;i++){
		if(s[i]!=s[num+1-i]) ct++;
	}
	cout<<ct;
	return 0;
}
