#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],num=1;
int find(int wz,int z){
	int cnt=1;
	for(int i=wz-1;i>=1;i--){
		if(a[wz]-a[i]<=z){
			z-=a[wz]-a[i];
			cnt++;
		}
		else{
			return cnt;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int f=find(i,m);
		if(num<f){
			num=f;
		}
	}
	cout<<num;
	return 0;
} 
