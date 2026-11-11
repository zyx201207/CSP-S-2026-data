#include<bits/stdc++.h>
using namespace std;
long long shui[500010];
long long qian[500010];
int z;
int n;
long long m;
bool check(int zhi,int gen){
	if(shui[gen]*(long long)(gen-zhi+1)-(qian[gen]-qian[zhi-1])<=m){
		return true;
	}
	else{
		return false;
	}
}
void erfen(int l,int r,int wei){
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid,wei)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	if(check(l,wei)){
		z=max(z,wei-l+1);
	}
	else{
		z=max(z,wei-r+1);
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>shui[i];
	}
	sort(shui+1,shui+n+1);
	for(int i=1;i<=n;i++){
		qian[i]+=qian[i-1];
		qian[i]+=shui[i];
	}
	for(int i=1;i<=n;i++){
		erfen(1,i,i);
	}
	cout<<z;
	return 0;
}
