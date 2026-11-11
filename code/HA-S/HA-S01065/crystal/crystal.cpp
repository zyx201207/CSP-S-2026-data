#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,maxn=-LLONG_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f_cha=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//ÅÐ¶ÏµÈ²î 
	long long k=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=k){
			f_cha=0;break;
		}
	}
	sort(a+1,a+n+1);
	if(f_cha==1){
		long long an=0,d=0;
		for(int i=1;;i++){
			an+=i*k;d++;
			if(an>m||d==n){
				cout<<d;
				return 0;
			}
		}
	}
	////////////////////////
	long long sum=0,shu=0;
	for(int i=1;i<=n;i++){
		sum=0,shu=0;
		for(int j=1;j<=i;j++){
			sum+=a[i]-a[j];shu++;
			if(sum>m){
				sum-=(a[i]-a[j]);shu--;
			}
		}
		if(shu>maxn){
			maxn=shu;
		}
	}
	cout<<maxn;
	return 0;
}
