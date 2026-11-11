#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
long long sum,ans;
const long long N=2e5+5;
struct node{
	long long e,shu;
}a[N];
long long ejz(long long s){
	sum=0;
	while(s>0){
		if(s%2==1){
			sum++;
			s/=2;
		}
		else s/=2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].shu<a[j].shu) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		a[i].e=ejz(a[i].shu);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].e<a[j].e) swap(a[i],a[j]);
		}
	}
	ans=a[1].shu;
	for(int i=2;i<=m;i++){
		ans&=a[i].shu;
	}
	cout<<ans;
	return 0;
}

