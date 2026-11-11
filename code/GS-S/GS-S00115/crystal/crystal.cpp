#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N];
int n,m;
bool cmp(int aa,int bb){
	return aa<bb;
}
int maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	sort(a+1,a+n+1,cmp);
	while(n>0){
		int sum=0;
		maxn=a[n];
		for(int i=1;i<=n;i++){
			sum+=(maxn-a[i]);
		}
		if(maxn>=sum){
			cout<<n;
			return 0;
		}else{
			n--;
		}
	}
	/*
	cout<<"0";
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(a[i]-a[j]<minn){
				minn=a[i]-a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]+1==a[j]||a[j]-a[i]==minn){
				a[i]+=1;
				m-=1;				
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(a[i]-a[j]<minn){
				minn=a[i]-a[j];
			}
		}
	}
	while(m>=minn){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+1==a[j]||a[j]-a[i]==minn){
					a[i]+=1;
					m-=1;
				}
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n;j++){
				if(a[i]-a[j]<minn){
					minn=a[i]-a[j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			sum++;
		}
	}
	cout<<sum;
	*/
	return 0;
}
