#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],manx=-1111;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		manx=max(manx,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	long long sum=a[1];
	if(m==n){
		for(int i=1;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0; 
	}
	if(m==1){
		cout<<manx;
		return 0;
	}
	if(m==2){
		int ma=-111;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<n;j++){
				int w=(a[i]&a[j]);
				ma=max(ma,w);
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=m;i++){
			sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}
