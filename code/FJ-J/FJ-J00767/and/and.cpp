#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],cnt[35],p[N],q;
string s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		long long x=a[i],k=30;
		while(k>=0){
			if(x>=pow(2,k)){
				x -= pow(2,k);
				s[i] += '1';
				cnt[30-k]++;
			}else s[i] += '0';
			k--;
		}
	}
	for(int i=0;i<=30;i++){
		if(!q && cnt[i]>=m){
			for(int j=1;j<=n;j++){
				if(s[j][i]=='1') p[++q] = j;
				else{
					for(int k=0;k<=30;k++){
						cnt[k] -= s[j][k]-'0';
					}
				}
			}
		}
		if(cnt[i]>=m && cnt[i]<q){
			for(int j=1;j<=q;j++){
				if(s[p[j]][i]=='0'){
					for(int k=0;k<=30;k++){
						cnt[k] -= s[p[j]][k]-'0';
					}
					p[j] = p[q];
					p[q] = 0;
					q--;
					j--;
				}
			}
		}
		if(q==m) break;
	}
	long long ans=a[p[1]];
	for(int i=1;i<=m;i++){
		ans &= a[p[i]];
	}
	cout << ans << '\n';
	return 0;
}
