#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N],b[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxn=-0x3f3f3f3f,minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i=minn;i<=maxn;i++){
		int nn=0,mm=m;
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
		for(int j=1;j<=n;j++){
			if(a[j]>i) break;
			else nn=j;
		}
		for(int j=nn;j>=1;j--){
			if(mm-i+a[j]<0) break;
			mm-=i-a[j];
			a[j]=i;
		}
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(a[j]==i) tmp++;
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}

