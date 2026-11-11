#include<bits/stdc++.h>
using namespace std;
int maxn=-1e9+1;
int n,m;
int a[200010];
int f=1;
long long hh=1;
int c[20010][10000];
int d[20010][10000];
int ha[20000010];
int ans;
int cd;
int ga(int b){
	if(b%2==0){
		return 0;
	}
	return 1;
}
int gg(int l){
	int aa=1;
	for(int i=1;i<=l;i++){
		aa*=2;
	}
	return aa;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//maxn=max(maxn,a[i]);
	}
	//sort(a+1,a+n+1);
	//for(int i=n;i>=1;i--){
	//	if(a[i]!=maxn){
	//		cout<<a[i]<<endl;
	//		break;
	//	}
	//}
	//while(a>0){
	//	char[i][1]=ga(a);
	//}
	for(int i=1;i<=n;i++){
		f=1;
		while(a[i]>0){
			c[i][f]=ga(a[i]);
			a[i]/=2;
			f++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=1e9;k++){
				if(c[i][k]&&c[j][k]){
					d[hh][k]=1;
				}
				ha[hh]=k;
			}
			hh++;
		}
	}
	f=0;
	for(int i=1;i<=hh;i++){
		if(maxn<=ha[i]){
			maxn=ha[i];
			f=i;
		}
	}
	cd=0;
	for(int i=maxn;i>=1;i--){
		ans+=d[f][i]*gg(cd);
	}
	cout<<ans<<endl;
	return 0;
}
