#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,sum;
struct A{
	int x;
	char c;
}a[200010];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].x;j++){
			s=s+a[i].c;
			r++;
		}
	} 
	while(l<r){
		if(s[l]!=s[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
// 
