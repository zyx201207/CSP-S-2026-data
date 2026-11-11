#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mx=0;
	for(int i=1;i<=n;i++){
		int j=1,k=i,t=m;
		while(k<=n){
			t-=j*(a[k+1]-a[k]);
			if(t<0)break;
			k++;
			j++;
		}
		mx=j>mx?j:mx;
	}
	cout<<mx;
	return 0;
} 
