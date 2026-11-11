#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma=-1,ans,mm=2e15,k[13];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		k[a[i]]++;
		ma=max(ma,a[i]);
	} 
	sort(a,a+n);
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(ma<4){
		if(k[3]>0){
			cout<<3;
			return 0;
		}
		if(k[2]>0&&k[1]>0){
			cout<<3;
			return 0;
		}
		if(k[2]>0){
			cout<<2;
			return 0;
		}
		if(k[1]>0){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<a[n-m];
	return 0;
}
