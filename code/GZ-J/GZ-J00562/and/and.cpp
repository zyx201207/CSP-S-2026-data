//GZ-J00562，戚星汉，贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],cnt[32],tmp,ans,n,m;
bool b[32][N],c[N],flag;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=31;j++){
			if((a[i]>>j)&1){
				cnt[j]++;
				b[j][i]=1;
			}
		}
	}
	for(int j=31;j>=0;j--){
		if(!flag){
			if(cnt[j]>=m){
				ans=(1<<j);
				for(int i=1;i<=n;i++){
					if(b[j][i]){
						c[i]=1;
					}
				}
				flag=1;
			}
		}
		else{
			tmp=0;
			for(int i=1;i<=n;i++){
				if(b[j][i]&&c[i]){
					tmp++;
				}
			}
			if(tmp>=m){
				for(int i=1;i<=n;i++){
					if(!b[j][i]&&c[i]){
						c[i]=0;
					}
				}
				ans+=(1<<j);
			}
		}
	}
	cout<<ans;
	return 0;
}
