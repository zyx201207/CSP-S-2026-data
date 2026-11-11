#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,cnt[5];
bool check(){
	for(int i=1;i<=n;i++)if(pow(2,(int)log2(a[i]+1))!=a[i])return false;
	return true;
}
bool check1(){
	if(pow(2,(int)(log2(n)))!=n)return false;
	for(int i=1;i<=n;i++)if(a[i]!=i-1)return false;
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++)if(a[i]>4)return false;
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		long long Max=0;
		for(int i=1;i<=n;i++)Max=max(Max,a[i]);
		cout<<Max;
		return 0;
	}else if(m==2){
		long long Max=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				Max=max(Max,(a[i]&a[j]));
			}
		}
		cout<<Max;
		return 0;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}else if(m==n-1){
		long long ans=a[1];
		for(int i=2;i<n;i++)ans=(ans&a[i]);
		cout<<ans;
	}else if(check()){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}else if(check1()){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}else if(check2()){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		if(cnt[4]>=m)cout<<4;
		else if(cnt[3]>=m)cout<<3;
		else if(cnt[2]>=m)cout<<2;
		else{
			if(cnt[3]+cnt[2]>=m)cout<<2;
			else if(cnt[3]+cnt[2]+cnt[1]>=m)cout<<1;
		}
	}
	return 0;
}
