#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,m;
bool pd(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i) return false;
	}
	return true;
}
int main(){
	//315275 3845
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(pd()){
		int l=1,r=n-1,id=0;
		while(l<=r){
			int mid=(l+r)/2;
			if((mid*mid+mid)/2<=m){
				l=mid+1;
				id=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<id<<endl;
		return 0;
	}
	int l=1,r=n,ma=0; 
	int x=0;
	for(int i=2;i<=n;i++){
		int m1=m,ans=0;
		while(a[i+1]==a[i]) i++;
		for(int j=i;j>=1;j--){
			if(m1>=a[i]-a[j]) ans++;
			else break;
			m1=m1-(a[i]-a[j]);
		}
		while(ans==i){
			if(m1>=ans*(a[i+1]-a[i])){
				i++;
				ans++;
			}else break;
			m1=m1-ans*(a[i+1]-a[i]);
		}
		ma=max(ma,ans);		
	}
	cout<<ma<<endl;
	return 0;
} 
/*
20 100
-6 -6 -5 -4 3 4 9 10 15 18 21 21 23 24 26 34 35 45 53 72
*/
