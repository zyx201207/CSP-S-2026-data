#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,m;
int a[N];
int ans=-1;
int t[35],P=-1;

void solve1(){
	for(int mask=0;mask<(1<<n);mask++){
		int k=-1,cnt=0;
		for(int i=0;(1<<i)<=mask;i++)if(mask&(1<<i)){
			cnt++;
			if(k==-1)k=a[i];
			else k&=a[i];
		}
		if(k==m){
			ans=max(ans,k);
			//cout<<t<<'\n';
		}
	}
	cout<<ans;
}

void solve2(){
	for(int i=0;i<n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
}

void solve3(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}

void solve4(){
	cout<<P;
}

void solve5(){
	for(int i=0;i<n;i++){
		int k=P;
		for(int j=0;(1<<j)<=a[i];j++)if((1<<j)&a[i]){
			if(t[j]==1)k=k|(1<<j);
		}
		ans=max(ans,k);
	} 
	cout<<ans;
}

void solve6(){
	sort(a,a+n);
	for(int i=n-1;i>=n-m;i--){
		if(ans==-1)ans=a[i];
		else ans&=a[i];
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	bool fa=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;(1<<j)<=a[i];j++){
			if((1<<j)&a[i]){
				t[j]++;
			}
			else fa=0;
		}
		if(P==-1)P=a[i];
		else P&=a[i];
	}
	
	if(n<=20){
		solve1(); 
		return 0;
	}
	if(m==1){
		solve2();
		return 0;
	}
	if(n<=5000&&m==2){
		solve3();
		return 0;
	}
	if(m==n){
		solve4();
		return 0;
	}
	
	if(m==n-1){
		solve5();
		return 0;
	}
	
	if(fa){
		solve6();
		return 0;
	}
	return 0;
}

