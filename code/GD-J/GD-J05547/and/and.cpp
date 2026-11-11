#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long n,m,x,ans,cnt;
int flag,f[maxn][maxn],s[40][maxn],num[40],a[maxn][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a1;
		cin>>a1;
		x=a1,cnt=1;
		while(x){
			if(x&1){
				num[cnt]++;
				s[cnt][num[cnt]]=i;
				a[i][cnt]=1;
			}
			x>>=1;
			cnt++;
		}
	}
	for(int l=30;l>=1;l--){
		if(num[l]<m) continue;
		if(num[l]==m){
			ans+=pow(2,l-1);
			for(int i=l-1;i>=0;i--){
				flag=1;
				for(int j=1;j<=num[l];j++){
					if(!a[j][i]){
						flag=0;
						break;
					}
				}
				if(flag) ans+=pow(2,i-1);
			}
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
