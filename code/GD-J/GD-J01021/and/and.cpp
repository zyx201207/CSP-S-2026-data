#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000006],p[1000006];
bool pd(int x){
	while(x!=0){
		int u=x%2;
		if(u!=1){
			return false;
		}
		x/=2;
	}
	return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int p1=1;
	int p2=1;
	int minz=100000000000000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!pd(a[i])){
			p1=0;
		}
		if(a[i]==0){
			cout<<0;
			return 0;
		}
		minz=min(minz,a[i]);
	}
	if(p1==1){
		cout<<minz;
		return 0;
	}
	int q=pow(2,n)-1;
	int maxz=0;
	for(int i=0;i<=q;i++){
		int a1=i;
		for(int i=1;i<=n;i++){
			p[i]=a1%2;
			a1/=2;
		}
		int cnt=0,sum=q;
		for(int i=1;i<=n;i++){
			if(p[i]){
				cnt++;
				sum=sum&a[i];
			}
		}
		if(cnt==m){
			maxz=max(maxz,sum);
		}
	}
	cout<<maxz;
	return 0;
} 
