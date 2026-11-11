#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	int l=0,r=s.size()-1;
	int ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans<<endl;
	return 0;
}
