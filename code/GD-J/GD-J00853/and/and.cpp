#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct node{
	string x;
}e[N];
int a[N];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int maxx=0;
	int x=1<<21;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx<<endl;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]); 
			}
		}
		cout<<ans<<endl;
		return 0;
	} 
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	else {
		sort(a+1,a+1+n,cmp);
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

