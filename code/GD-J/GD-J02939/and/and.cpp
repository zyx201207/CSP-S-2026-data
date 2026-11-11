#include<bits/stdc++.h>
using namespace std;
int a[200005] 
map<int,bool>mp;
map<int,int>ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=18;i++){
		mp[1<<i]=true;
	}
	int n,m,flg=0,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp.count(a[i])){
			flg++;
		}
		mx=max(mx,a[i]);
		ma[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	bool flag=true;
	for(int i=0;i<=18;i++){
		if(n==(1<<i)-1){
			flag=true;
			break;
		}
	}
	if(!flag&&flg==n){
		cout<<a[m];
		return 0;
	}else{
		if(m<=n/2){
			cout<<0;
		}else if(n%2==0){
			cout<<n-((m+1)/2)*2;
		}else{
			cout<<(n-1)-((m+1)/2)*2;
		}
		return 0;
	}
	if(m==2){
		cout<<a[2+n%2];
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(mx<4){
		if(a[m]>=2){
			cout<<a[m];
		}else if(ma[3]+ma[1]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 50-50;
} 
