#include<bits/stdc++.h>
using namespace std;
long long a[500005],desk[500005],sum[300005];
int check(long long num,int n){
	for(int i=1;i<=n;i++){
		if(desk[i]==num){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			desk[j]=0;
		}
		int r=1;
		for(int j=i;j<=n;j++){
			int pos=check(a[j],n);
			if(pos==-1){
				desk[r]=a[j];
				r++;
			}else{
				for(int z=pos;desk[z]!=0;z++){
					desk[z]=0;
				}
				desk[pos]=a[j];
				r=pos+1;
			}
		}
		for(int j=1;j<=n;j++){
			if(desk[j]!=0){
				sum[desk[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
