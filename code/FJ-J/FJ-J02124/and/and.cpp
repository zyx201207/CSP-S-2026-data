#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005],va1,b[5];
int sma(int s,int mi,int r){
	if(r==m) {for(int i=1+s;i<=n;i++){mi=max(mi,a[i]);}return 0;}
	for(int i=1+s;i<=n;i++){
		int va=a[i]||sma(i,0,r+1);
		mi=max(mi,va);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	if(n==m){
		for(int i=1;i<=n;i++){
			cin>>a[0];ans=ans||a[0];
		}
		cout<<ans;return 0;
	}
	if(m=1){
		for(int i=1;i<=n;i++){cin>>a[0];ans=max(ans,a[0]);}
		cout<<ans;return 0;
	}
	
	if(n<=2000||m==2){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				va1=a[i]||a[j];
				ans=max(ans,va1);
			}
		}
		cout<<ans;return 0;
	}
	if(m>=3){
		bool flag=1;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			if(a[i]<=4) b[a[i]]++;
			else flag=0;
		}
		if(flag==1){
			if(b[4]>=m) {cout<<"4\n";return 0;}
			if(b[3]>=m) {cout<<"3\n";return 0;}
			if(b[3]+b[2]>=m) {cout<<"2\n";return 0;}
			if(b[1]>=m) {cout<<"1\n";return 0;}
			else {
			cout<<"0\n";return 0;}
		}
		cout<<sma(0,0,0);return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					va1=a[i]||a[j]||a[k];
					ans=max(ans,va1);
				}
			}
		}
		cout<<ans;return 0;
	}
}
