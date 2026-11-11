#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],ans;
bool flag[N];
void f(int x,int y){
	if(x==m){
		ans=max(ans,y);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=true;
			f(x+1,(y & a[i]));
			flag[i]=false;
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		int b=1;
		while(a[i]>=b){
			b*=2;
		}
		if(b-1!=a[i]) return false; 
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==m){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(check()){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	f(0,1048575);
	cout<<ans;
	return 0;
}
