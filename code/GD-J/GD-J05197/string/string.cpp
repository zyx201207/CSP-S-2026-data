#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a[200005],l=0,r,cnt=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	cout<<s<<endl;
	r=s.size()-1;
	while(!(l==r+1||l==r)){
		if(s[l]!=s[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
