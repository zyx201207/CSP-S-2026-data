#include<bits/stdc++.h>
using namespace std;
long long n,maxn,maxn_,m,sum,sumn,arr[200010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		maxn=max(maxn,arr[i]);
		if(i==1) sumn=arr[i];
		else sumn=sumn&arr[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<sumn;
		return 0;
	}
	else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) maxn=max(maxn,arr[i]&arr[j]);
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			maxn_=max(maxn_,(maxn^arr[i]));
		}
		cout<<maxn_;
		return 0;
	}
	else{
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=m;i++){
			if(i==1) sumn=arr[i];
			else sumn=sumn&arr[i];
		}
		cout<<sumn;
		return 0;
	}
}
