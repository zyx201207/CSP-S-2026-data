#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,b[500005],c[500005];
bool cmp(int x,int y){
	return x<y;
}
bool check(){
	for(int i=0;i<n;i++){
		if(a[i]!=i)return 0;
	}
	return 1;
}
bool check2(){
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n<=10000){
		for(int i=0;i<n;i++){
			long long sum=0,maxn=0;
			for(int j=i;j>=0;j--){
				if(sum+(a[i]-a[j])<=m)sum+=a[i]-a[j],maxn++;
				else break;
			}
			ans=max(ans,maxn);
		}
	}
	else if(check()){
		long long sum=0,maxn=0;
		for(int i=0;i<n;i++){
			if(sum+i<=m)maxn++;
			else break;
		}
		ans=maxn;
	}
	else if(check2()){
		long long sum=0,maxn=0,cha=a[1]-a[0];
		for(int i=0;i<n;i++){
			if(sum+i*cha<=m)maxn++;
			else break;
		}
		ans=maxn;
	}
	cout<<ans;
}
