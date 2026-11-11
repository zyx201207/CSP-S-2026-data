#include<bits/stdc++.h>

using namespace std;

int n,m;
long long a[200010],sum=0;
map<int,int>mp;
bool book[200010];
void dfs(int now,int g,long long yi){
	if(g==1) yi=a[now];
	else yi&=a[now];
	if(g==m) sum=max(sum,yi);
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			dfs(i,g+1,yi);
		}
	}
}
int work1(){
	long long ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	return ans;
}
int work2(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) ans=max(ans,a[i]&a[j]);
		}
	}
	return ans;
}
int workn(){
	long long ans=a[1];
	for(int i=2;i<=n;i++) ans&=a[i];
	return ans;
}
int work114(){
	if(mp[4]>=m) return 4;
	else if(mp[3]>=m) return 3;
	else if(mp[2]>=m) return 2;
	else if(mp[3]+mp[2]>=m) return 2;
	else if(mp[1]>=m) return 1;
	else if(mp[4]+mp[2]>=m) return 1;
	else if(mp[3]+mp[1]>=m) return 1;
	else if(mp[4]+mp[2]+mp[1]>=m) return 1;
	else return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
	if(m==1){
		cout<<work1();
		return 0;
	}
	if(m==2){
		cout<<work2();
		return 0;
	}
	if(m==n){
		cout<<workn();
		return 0;
	}
	bool f=0,f2=0;
	for(int i=1;i<=n;i++){
		int l=a[i]+1;
		while(l>1){
			if(l%2!=0) f=1;
			l/=2;
		}
		if(a[i]>4) f2=1;
	}
	if(!f){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(!f2){
		cout<<work114();
		return 0;
	}
	dfs(0,0,0);
	cout<<sum<<endl;
	return 0;
} 
