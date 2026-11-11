#include<bits/stdc++.h>
using namespace std;
int a[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int s=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]<s){
			s=i;
		}
	}
	int l,r,in_l,in_r;
	l=s;
	r=s;
	while(1){
		if(r+1<=n){
			if(a[r+1]-a[r]<=m){
				in_r=a[r+1]-a[r];
			}else
				in_r=-1;
		}else
			in_r=-1;
		if(l-1>=1){
			if(a[l]-a[l-1]<=m){
				in_l=a[l]-a[l-1];
			}else
				in_l=-1;
		}else
			in_l=-1;
		if(in_l==-1 && in_r==-1)
			break;
		if(in_l!=-1 && in_r!=-1){
			if(in_r<=in_l){
				m=m-a[r+1]+a[r];
				a[r]+=a[r+1]-a[r];
				r++;
			}else{
				m=m-a[l]+a[l-1];
				a[l-1]+=a[l]-a[l-1];
				l--;
			}
		}else if(in_l==-1){
			r++;
			m=m-a[r+1]+a[r];
		}else if(in_r==-1){
			l--;
			m=m-a[l]+a[l-1];
		}else
			break;
		if(a[r+1]-a[r]>m && a[l]-a[l-1]>m)
			break;
	}
	cout<<r-l+1;
	return 0;
} 
