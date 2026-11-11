#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,ans=0,l,r;
string s,tmp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>tmp;
		for(int j=0;j<a[i];j++){
			s+=tmp;
		}
	}
	long long len=s.size();
	l=0;
	r=len-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0; 
}
