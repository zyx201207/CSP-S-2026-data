#include<bits/stdc++.h> 
using namespace std;
long long cnt;
struct Node{
int nu;
char ch;
} a[1001];
int cmp(Node x,Node y){
	return x.nu>y.nu;
}
string s,l;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].nu>>a[i].ch;
		for(int j=0;j<a[i].nu;j++){
			s+=a[i].ch;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		l+=s[i];
	}
	bool jh=0;
	for(int i=0;i<s.size();i++){
		if(l[i]!=s[i])jh=1;
	}
	if(jh==0){
	cout<<0;
	return 0;
}
int r=s.size()-1,l=0;
while(l<=r){
	if(s[r]!=s[l]){
		cnt++;
	}
	l++;
	r--;
}
cout<<cnt;
	return 0;
}
