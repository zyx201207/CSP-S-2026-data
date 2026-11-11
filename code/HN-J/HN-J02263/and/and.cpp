#include<bits/stdc++.h>
#define int long long
#define fayuge else cout<<ans
using namespace std;
int n,m;
int a[200100];
bool ispow(int num){
	while(num>1){
		if(num % 2 == 1){
			return false;
		}
		num /= 2; 
	}
	return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	sort(a+1,a+1+n,[](int i,int j){return i>j;});
	int ans=0;
	int p=1;
	if(ispow(a[1])){
		if(a[1]==a[m]){
			cout<<a[1];return 0;
		}
		
	}
	for(int x=1;x<=n;x++){
		if(ispow(a[x]))continue;
		else {ans=a[x],p=x+1,m--;break;}
	}
	while(m!=0 && p<=n){
		if(ispow(a[p])){
			p++;
			continue;
		}
		ans &= a[p];
		p++;
		m--;
	}
	if(m > 0)cout<<0;
	fayuge;
	return 0;
}
