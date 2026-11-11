#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[1000001];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			b[i]+=a[i]-a[j];
			if(b[i]==m){
				cout<<i-j+1;
				return 0;
			}
		}
	}
	cout<<1;
	return 0;
}
