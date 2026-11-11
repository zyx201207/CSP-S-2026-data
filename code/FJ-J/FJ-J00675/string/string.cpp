#include <bits/stdc++.h>
using namespace std;
long long n,ti=1,ans,a[222222][5],t;
char s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>s;
		a[i][1]=s-'a';
		a[i][2]=t;
	}
	for(int l=1,r=n;r>l;){
		ti=min(a[l][2],a[r][2]);
		if(a[l][1]!=a[r][1]){
			ans+=ti;
		}
		if(a[l][2]>a[r][2]){
			a[l][2]-=a[r][2];
			r--;
		}
		else if(a[l][2]<a[r][2]){
			a[r][2]-=a[l][2];
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ans;
	
	
	return 0;
}
