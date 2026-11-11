//GZ-S00292 πÛ—Ù“ª÷– –ÏΩı∫Ë 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],maxn,r=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1]>>a[2];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) r=0;
	} 
	if(r){
		int cnt=1,k=1;
		while(1){
			if(m-cnt*(a[2]-a[1])<0) break;
			m-=cnt*(a[2]-a[1]),cnt++,k++;
		}
		cout<<k;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int mm=m,cnt=1,l=i-1,r=i+1,kk=0;
		while((mm>=0)&&(l>0||r<=n)){
			if((a[i]-a[l]<=cnt*(a[r]-a[i]-kk)&&l>0)||r>n){
				mm-=a[i]-a[l];
				if(mm>=0&&l>=1) cnt++,l--;
			}else if((a[i]-a[l]>=cnt*(a[r]-a[i]-kk)&&r<=n)||l<1){
				mm-=(a[r]-a[i]-kk)*cnt;
				kk=a[r]-a[i];
				if(mm>=0&&r<=n) cnt++,r++;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}

