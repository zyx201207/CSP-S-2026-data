#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int check(int k,int s){
	int  man=-1;
	for(int i=k+1;i<=n;i++){
		man=max(man,(a[i]&s));
	}
	return man;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==2){
		maxn=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int t=a[1];
		for(int i=2;i<=n;i++){
			t=(t&a[i]);
		}
		cout<<t;
	}
	else{
		int l=1,t=a[1];
		for(int i=1;i<=m;i++){
			t=check(l+1,t);
			l++;
		}
		cout<<t;
	}
	return 0;
}
