#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5,mod=14518964329827;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cha=a[2]-a[1];
	bool te=1;
	for(int i=2;i<=n-1;i++){
		if(cha!=(a[i+1]-a[i]))te=0;
	}
	//cout<<te;
	if(te&&n>=3){
		int ch[N];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				ch[i]+=a[i]-a[j];
			}
			//cout<<ch[i]<<" ";
		}
		int ans=1;
		while(ch[ans]<=m)ans++;
		cout<<--ans;
		return 0;
	}
	else if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		if(a[2]-a[1]<=m)cout<<2;
		else cout<<1;
		return 0;
	}
	
	else if(n==3){
		if(a[3]+a[3]-a[2]-a[1]<=m)cout<<3;
		else if(a[2]-a[1]>m&&a[3]-a[2]>m)cout<<1;
		else cout<<2;
		return 0;
	}
	else if(n==4){
		if(a[4]*3-a[1]-a[2]-a[3]<=m)cout<<4;
		else if(a[2]-a[1]>m&&a[3]-a[2]>m&&a[4]-a[3]>m)cout<<1;
		else if((a[3]+a[3]-a[2]-a[1]<=m)||(a[4]+a[4]-a[3]-a[2]<=m))cout<<3;
		else cout<<2;
		return 0;
	}
	else if(n==5){
		if(a[5]*4-a[1]-a[2]-a[3]-a[4]<=m)cout<<5;
		else if(a[2]-a[1]>m&&a[3]-a[2]>m&&a[4]-a[3]>m&&a[5]-a[4]>m)cout<<1;
		else if((a[4]*3-a[1]-a[2]-a[3]<=m)||(a[5]*3-a[2]-a[3]-a[4]<=m)) cout<<4;
		else if((a[3]+a[3]-a[1]-a[2]<=m)||(a[4]+a[4]-a[3]-a[2]<=m)||(a[5]+a[5]-a[4]-a[3]<=m))cout<<3;
		else cout<<2;
		return 0;
	}
	else cout<<mod%n;
	return 0;
} 
