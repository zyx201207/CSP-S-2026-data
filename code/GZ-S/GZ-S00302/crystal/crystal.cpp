//GZ-S00302 郭雨晨 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],s;
bool check(int x){
	int t=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x){
			t+=x-a[i];
			if(t>m) return false;
		}
		
	}
	return true;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int lt=a[1],rt=a[n];
	while(lt<=rt){
		int mid=(lt+rt)/2;		
		if(check(mid)) {
			lt=mid+1;
			
		}
		else{
			rt=mid-1;
		} 
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=lt) s++;
	}
	cout<<s;
	return 0;
}

