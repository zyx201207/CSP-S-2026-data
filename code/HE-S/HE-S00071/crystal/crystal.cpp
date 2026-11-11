#include<bits/stdc++.h>
using namespace std;
int ans=0,p;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500005];
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=d)f=0;
	}
	if(f){
		int t=a[2]-a[1];
		int i=1;
		while(m-t*i>=0){
			m-=t*i;
			i++;
		}
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1);
	int j=1;
	for(int i=2;i<=n;i++){
		if(ans>m){
			break;
		}
		ans+=(a[i]-a[i-1])*j;
		a[i-1]=a[i];
		j++;
		p=j-1;
	}
	cout<<p;
	return 0;
}
