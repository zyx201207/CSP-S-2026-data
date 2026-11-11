#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005][33];bool b[200005];long long ans=0,er[33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int w;
		cin>>w;
		int cnt=0;
		while(w!=0){
			a[i][cnt]=w%2;
			w/=2;cnt++;
		}
	}er[0]=1;
	for(int i=1;i<=32;i++){
		er[i]=er[i-1]*2;
	}
	for(int i=32;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&b[j]==0)cnt++;
		}
		if(cnt>=m){
			ans+=er[i];
			for(int j=1;j<=n;j++){
				if(a[j][i]==0)b[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
//5 3
//31 3 1 15 7
