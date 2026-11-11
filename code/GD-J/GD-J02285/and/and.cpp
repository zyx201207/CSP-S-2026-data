#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
const int maxn=2e5+5;
int a[maxn],cnt[31];
int v[31][maxn];
int read(){
	int x=0,ch=gc();
	while (!isdigit(ch)) ch=gc();
	while (isdigit(ch)) {
		x=x*10+ch-'0';
		ch=gc();
    }
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read();
	int ans=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		for (int j=0;j<31;j++){
			if (a[i]&(1<<j)){
				v[j][cnt[j]++]=a[i];
			}
		}
	}
	for (int i=30;i>=0;i--){
		if (cnt[i]>=m){
			ans|=(1<<i);
			for (int j=i-1;j>=0;j--){
				cnt[j]=0;
			}
			for (int j=0;j<cnt[i];j++){
				int x=v[i][j];
				for (int k=i-1;k>=0;k--){
					if (x&(1<<k)){
						v[k][cnt[k]++]=x;
					}
				}
			}
			cnt[i]=0;
		}
		else {
			cnt[i]=0;
		}
	}
	cout << ans;
	return 0;
}
