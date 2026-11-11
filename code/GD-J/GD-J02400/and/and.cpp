#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200010],b[33][200010],c[200010],d[33],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				b[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			d[j]+=b[j][i];
		}
	}
	for(int i=30;i>=0;i--){
		if(d[i]>=m){
			for(int j=1;j<=n;j++){
				if(b[i][j]){
					c[j]++;
				}
			}
		}
	}
	sort(c+1,c+n+1);
	ans=c[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans&=c[i];
	}
	cout<<ans<<endl;
	return 0;
}
