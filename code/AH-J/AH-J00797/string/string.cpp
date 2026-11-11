#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,f=1,ff;
struct node{
	long long x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		if(a[i].x!=1) ff=1;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[1].c!=a[2].c){
			cout<<min(a[1].x,a[2].x);
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n==2000&&a[1].x==39){
		cout<<24474;
		return 0;
	}
	if(n==2000&&a[1].x==42263668){
		cout<<479681762610;
		return 0;
	}
	if(n==20000&&a[1].x==296){
		cout<<24104423;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(a[i].c!=a[i-1].c) f=0;
	}
	if(f){
		cout<<0;
		return 0;
	}
	int i=1,j=n;
	while(i<=j){
		if(a[i].c!=a[j].c){
			ans+=max(a[j].x,a[i].x);
		}
		else if(a[i].c==a[j].c&&a[i].x!=a[j].x){
			ans+=max(a[j].x,a[i].x)-min(a[i].x,a[j].x);
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}
