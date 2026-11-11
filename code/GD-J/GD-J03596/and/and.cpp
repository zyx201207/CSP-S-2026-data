#include<bits/stdc++.h>
using namespace std;
long long n,m,a[222222];
long long cnt_and;
void solve1(){
	long long ans=-99999;
	for(long long s=0;s<(1<<n);s++){
		long long tot_choices=0,totand=-1;
		for(int i=0;i<n;i++){
			if(s&(1<<i)){
				tot_choices+=1;
				if(totand==-1){
					totand=a[i+1];
				}else{
					totand&=a[i+1];
				}
			}
		}
		if(tot_choices==m){
			ans=max(ans,totand);
		}
	}
	cout<<ans;
	return;
}
void solve2(){
	sort(a+1,a+n+1);
	cout<<a[n];
	return;
}
void solve3(){
	int totand=a[1];
	for(int i=2;i<=n;i++){
		totand&=a[i];
	}
	cout<<totand;
	return;
}
void solve4(){
	long long ans=-99999;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}else{
				ans=max(a[i]&a[j],ans);
			}
		}
	}
	cout<<ans;
	return;
}
int turn(int x){
	int y=0;
	for(int i=0;x;i++){
		y+=((x%2)^1)*(1<<i);
		x/=2;
	}
	return y;
}
void solve5(){
	int ans=-99999;
	for(int i=1;i<=n;i++){
		int now=(turn(cnt_and^a[i]));
		ans=max(now,ans);
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt_and=(i==1 ? a[1] : cnt_and&a[i]);
	}
	if(m==1){
		solve2();
		return 0;
	}
	if(m==n){
		solve3();
		return 0;
	}
	if(m==2){
		solve4();
		return 0;
	}
	if(n<=20){
		solve1();
		return 0;
	}
	if(m==n-1){
		solve5();
		return 0;
	}
} 
