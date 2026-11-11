#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100000005],b[100000005];//b[i][j]=a[]-a[]
long long ma=-123456;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int x=m;cnt=0;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(x==0)break;
				b[j]=b[k]+1;x--;
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[j]==a[k]){
					cnt++;
				}
			}
		}
		ma=max(cnt,ma);
	}
	cout<<ma-2;
	return 0;
}

