#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000],maxn=0,t,ans;
long long cnt=0;

int toufen(){
	t=m,cnt=1;
	while(t>0 and t>=cnt){
		t-=cnt;
		cnt+=1;
		ans++;	
	}
	return ans+1;
}

int baoli(){
	for(long long i=2;i<=n;i++){
		t=m,ans=0;
		for(long long j=i-1;j>=1;j--){
			if(t<0 and a[j]+t<a[i])break;
			if(a[i]-a[j]<=t)ans++,t-=(a[i]-a[j]);
		}
		maxn=max(ans,maxn);
	}
	return maxn;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==1)cnt++;
	}
	
	if(cnt==n-1){
		cout<<toufen();
		return 0;	
	}else{
		if(baoli()==0)cout<<0;
		else cout<<baoli()+1;
		return 0;	
	}
	 
}
