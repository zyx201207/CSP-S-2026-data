#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int l,y,e,sa,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	long long mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(a[i]==0){
			l++;
		}
		if(a[i]==1){
			y++;
		}
		if(a[i]==2){
			e++;
		}
		if(a[i]==3){
			sa++;
		}
		if(a[i]==4){
			s++;
		}
	}
	if(mx<=4){
		if(s>=m){
			cout<<4;
			return 0;
		}else if(sa>=m){
			cout<<3;
			return 0;
		}else if(sa+e>=m||e>=m){
			cout<<2;
			return 0;
		}else if(sa+y>=m||y>=m){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
