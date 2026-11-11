#include <bits/stdc++.h>
using namespace std;
long long ans=0,n,x,a[200005],num=0;
string s,y; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		s+=y;
		a[i]=x;
		num+=x;
	}
	num/=2;
	int l=1,r=n;
	while(num--){
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		if(s[l-1]!=s[r-1]){
			ans++;
	    	a[l]--;
	    	a[r]--;
		}
	}
	cout<<ans;
	return 0;
}
