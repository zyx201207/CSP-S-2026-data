#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],b[N],s=0,k=1;
int f(){
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(f()){
		int x=m/(a[2]-a[1]);
		while(x>=k){
			x-=k;
			k++;
			s++;
		}
		cout<<s+1;
		return 0;
	}
	while(m>0){
		int minn=INT_MAX,mini=0;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]<minn&&a[i]-a[i-1]!=0){
				minn=a[i]-a[i-1];
				mini=i-1;
			}
		}
		if(m>=minn){
			m-=minn;
			s++;
			a[mini]=a[mini+1];
		}
		else break;
	}
	cout<<s;
	return 0;
}
