#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],f[200005];
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	int n,m,bg=1;
	int t[60];
	for(int i=0;i<=60;i++){
		t[i]=(1<<i)-1;
	}
	bool f1=0,f2;
	int is1=0,is2=0;
	cin>>n>>m;
	for(int i=1;i<=n){
		cin>>a[i];
		for(int j=0;j<=60;j++){
			if(t[j]==a[i]){
				is1++;
				break;
			}
		}
		if(a[i]==i-1)is2++;
		if(a[i]>4)f1=1;
	}
	if(m=1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>ans)ans=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>ans)ans=a[i]&a[j];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		vector<int> pre(n+5);vector<int> suf(n+5);
		pre[0]=(1<<60)-1;
		suf[n+1]=(1<<60)-1;
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]&=a[i];
		}
		for(int i=n;i>=1;i--){
			suf[i]=suf[i+1]&a[i];
		}
		int ans=0; 
		for(int i=1;i<=n;i++){
			if(suf[i+1]+pre[i+1]>ans)ans=suf[i+1]+pre[i+1];
		}
		cout<<ans;
	}
	if(!f1){
		int fg=0;
		for(int i=1;i<=n;i++){
			if(i==4)fg++;
		}
		if(fg>=m)cout<<4;
		else{
			fg=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2||a[i]==3)fg++;
			}
			if(fg>=m)cout<<2;
			else cout<<1;
		}
	}
	return 0;
}
