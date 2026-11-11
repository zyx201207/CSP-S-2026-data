#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int maxn=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i ++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(a[1]<4){
		for(int i=1;i<=m;i++)maxn&=a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=j){
				int x=a[i]&a[j];
				if(x>=maxn)maxn=x;
			}
		}
	}
	cout<<maxn;
	return 0;
} 
