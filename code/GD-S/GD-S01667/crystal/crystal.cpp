#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long m;
int a[N],sm,mx,n,sm1,sm2;
bool flag,flag1;
int main(){
	freopen("crystal.cpp","r",stdin);
	freopen("crystal.cpp","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) sm++;
	}
	int dc = a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]==dc&&dc!=1) flag1=1;
	}
	if(sm==n) flag=1;
	if(flag){
		for(int i=1;i<=n;i++){
			sm1+=i;
			if(sm1>m){
				cout<<i;
				break;
			} 
			else if(sm1==m){
				cout<<i+1;
				break;
			}
		}
		return 0;
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			sm2+=dc*i;
			if(sm2>m){
				cout<<i;
				break;
			} 
			else if(sm2==m){
				cout<<i+1;
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=m,cnt=0;
		for(int j=i-1;j>=1;j--){
			if(x<a[i]-a[j]) break;
			x-=a[i]-a[j];
			cnt++;
		}
		mx=max(cnt,mx);
	} 
	cout<<mx+1;
	return 0;
} 
