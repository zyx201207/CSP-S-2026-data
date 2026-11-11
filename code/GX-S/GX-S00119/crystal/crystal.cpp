#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500010],b[500009];
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int sum=1;
	for(int i=n;i>1;i--){
		int s=1;
		long long km=0,lj=0;
		for(int j=i-1;;){
			lj+=b[j];
			km+=lj;
			if(km>m||j<1){
				break;
			}
			j--;
			s++;
		}
		sum=max(sum,s);
	}
	cout<<sum;
	return 0;
}
