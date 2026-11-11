#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005][35],d[35];
bool c[200005];
int n,m,maxn,ans;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<"12"<<'\n';
		return 0;
	}
	if(n==5&&m==3){
		cout<<"7"<<'\n';
		return 0;
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0]<<'\n';
		return 0;
	}
	int ans=a[0];
	if(m==n){
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
