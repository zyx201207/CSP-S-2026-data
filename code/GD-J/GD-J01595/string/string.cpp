#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ts1=1,ts2=1,mn=INT_MAX,sm;
char mp[N];
struct node{
	int a;
	char c;
}a[N];
char f(int x){
	if(x<=a[1].a){
		return a[1].c;
	}
	int sm=0;
	for(int i=1;i<=n;i++){
		sm+=a[i].a;
		if(x<=a[i].a)
		return a[i].c;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		if(a[i-1].c!=a[i].c&&i!=1){
			ts1=0;
		}
		if(a[i].a>=500){
			ts2=0;
		}
		sm+=a[i].a;
	}
	if(ts1){
		cout<<0;
		return 0;
	}
	if(sm<=N){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].a;j++){
				mp[++cnt]=a[i].c;
			} 
		}
		int mn=INT_MAX,ans=0;
		for(int i=1;i<=cnt/2;i++){
			if(mp[i]!=mp[cnt-i+1]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(int i=1;i<=sm/2;i++){
			if(f(i)!=f(sm-i+1)){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
