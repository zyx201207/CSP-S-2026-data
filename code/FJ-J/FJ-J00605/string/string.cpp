#include<bits/stdc++.h>
using namespace std;
int n,l=0,r,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		while(x>0){
			s+=y;
			x-=1;
		}
	}
	int i=s.size();
	r=i-1;
	if(i%2==0) i/=2-1;
	else i/=2;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
