#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	if(n>2000){
		int ans=a[0];
		for(int i=1;i<m;i++) ans&=a[i];
		int sum=a[n-1];
		for(int i=n-2;i>=n-m;i--) sum&=a[i];
		cout<<max(ans,sum);
	}else if(m==n) cout<<a[0];
	else if(m==2){
		int mx=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else if(m==1) cout<<a[0];
	else if(m==3){
		int mx=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int x=j+1;x<n;x++) mx=max(mx,a[i]&a[j]&a[x]);
			}
		}
		cout<<mx;
	}else if(m==4){
		int mx=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int x=j+1;x<n;x++) for(int y=x+1;y<n;y++) mx=max(mx,a[i]&a[j]&a[x]&a[y]);
			}
		}
		cout<<mx;
	}else if(m==5){
		int mx=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int x=j+1;x<n;x++) for(int y=x+1;y<n;y++) for(int z=y+1;z<n;z++) mx=max(mx,a[i]&a[j]&a[x]&a[y]&a[z]);
			}
		}
		cout<<mx;
	}
	return 0;
}
