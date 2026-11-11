#include<iostream>
#include<cmath>
using namespace std;
const int N=2e5+5,M=35;
int n,m,a[N],b[N][M],cnt[M],ans[M];
long long cou;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++){
			b[i][30-j]=(a[i]>>j)&1;
		}
		for(int j=1;j<=30;j++){
			if(b[i][j]&1){
				cnt[j]++;
			}
		}
	}
	for(int k=1;k<=30;k++){
		if(cnt[k]>=m){
			int ccc=0;
			for(int i=1;i<=n;i++){
				bool fla=true;
				for(int j=1;j<=30;j++){
					if(j==k&&b[i][j]!=1){
						fla=false;
						break;
					}
					if((ans[j]&1)&&!(b[i][j]&1)){
						fla=false;
						break;
					}
				}
				if(fla)ccc++;
			}
			if(ccc>=m){
				ans[k]=1;
			}
		}
	}
	long long pp=1;
	for(int i=30;i>=1;i--){
		cou+=pp*ans[i];
		pp*=2;
	}
	cout<<cou;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
