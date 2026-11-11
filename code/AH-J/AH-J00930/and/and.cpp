#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<string>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;i<=n;j++){
				if((a[i]&a[j])>=ans){
					ans=(a[i]&a[j]);
					cout<<ans<<endl;
					}}}}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;i<=n;j++){
				for(int s=j+1;s<=n;s++){
				if((a[i]&a[j]&a[s])>=ans){
					ans=(a[i]&a[j]&a[s]);
					cout<<ans<<endl;
					}}}}}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);cout<<ans<<endl;}}
	cout<<ans;
	return 0;
}
