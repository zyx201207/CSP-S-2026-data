#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	if(x>y) return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[99999],k,l=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	k=n-1;
	for(int i=0;i<n;i++){
		if(a[0]+m>=a[k]){
			break;
		}else k--;
	}
	for(int i=k;i>=0;i--){
		for(int j=0;j<=k;j++){
			l+=a[i];
		}
		if((l+m)/(k+1)>=a[k]){
		   cout<<k+1;
		   return 0;
		}
	}
	return 0;
} 
