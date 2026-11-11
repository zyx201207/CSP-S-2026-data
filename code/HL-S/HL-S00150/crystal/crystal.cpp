#include <bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],n,m,ans=1;
long long crystal(long long maxx,int p){
	long long t=m,anss=1;
	for(int j=p-1;j>=1;j--){
		int cha=maxx-a[j];
		if(t>=cha){
			t-=cha;
			anss+=1;
		}else{
			return anss;
		}
	}
	return anss;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(a[i]==a[i+1]){
			b[i]==0;
		}
		if(i!=1&&b[i]==1){
			ans=max(crystal(a[i],i),ans);
		}else{
			continue;
		}
	}
	cout<<ans;
	return 0;
}
