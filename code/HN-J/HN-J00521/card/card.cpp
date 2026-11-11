#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
const int maxn1=3e5+10;
struct node{
	int zhi;
	int wei;
};
int a[maxn];
node b[maxn1];
int cun[maxn];
int ans[maxn1];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cun[a[i]]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[j].wei=0;
			b[j].zhi=0;
		}
		if(i>=1){
			cun[a[i-1]]--;
		}
		for(int q=i;q<n;q++){
			
			if(b[a[q]].zhi==0){
				b[a[q]].zhi++;
				b[a[q]].wei=q;
			}
			else{
				for(int j=b[a[q]].wei;j<=q;j++){
					b[a[j]].wei=0;
					b[a[j]].zhi=0;
				}
				b[a[q]].wei=q;
				b[a[q]].zhi=1;
			}
		}
		for(int j=0;j<=m;j++){
			if(cun[j]>0) ans[j]+=b[j].zhi;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
