#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,a[N],b[N],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=-11111;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn<<endl;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			b[i]=(b[i-1]&a[i]);
		}
		cout<<b[n]<<endl;
	}else if(m==2){
		int maxn=-11111;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int f=(a[i]&a[j]);
				maxn=max(f,maxn);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}

