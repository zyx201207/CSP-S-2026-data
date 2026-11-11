#include<bits/stdc++.h>
using namespace std;
long long tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long tou=n,js=0;
	int f=0;
	for(int i=0;i<n;i++){
		tou=n;
		js=0;
		f=0;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				if(j>js)js=j;
				if(i<tou)tou=i;
				f=1;
			}
		}
		if(f==1){
			for(int k=i;k<tou;k++){
				tong[a[k]]++;
			}
			for(int l=js;l<n;l++){
				tong[a[l]]++;
			}
		}
		else{
			for(int k=i;k<tou;k++){
				tong[a[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
