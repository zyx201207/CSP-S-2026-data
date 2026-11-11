#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int x;
	char y;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,j=0,v=0;
	string s;
	cin>>n;
	cin>>a[1].x>>a[1].y;
	for(int i=1;i<=a[1].x;i++) s+=a[i].y;
	for(int i=2;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		v+=a[i].x;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].y;
		}
	}
	int l=0,r=v-1;
	while(1){
		if(s[l]!=s[r]) j++;
		if(l==r&&r==l+1) break;
		l++,r--;
	}
	cout<<j;
	return  0;
}
