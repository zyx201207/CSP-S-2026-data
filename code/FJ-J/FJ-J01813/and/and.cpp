#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[32],c[32],d[200005],klj,fucker=1;
int b[200005][32]; 
pair <int,int> aa[200005];
int cmp(pair <int,int> fu,pair <int,int> ck){
	if(fu.first!=ck.first){
		return fu.first>ck.first;
	}else{
		return fu.second>ck.second;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cnt[0]=1;
	cin>>n>>m;
	for(int i=1;i<=30;i++){
		cnt[i]=cnt[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=1&&i!=1){
			fucker=0;
		}
		aa[i].second=a[i];
	}
	if(fucker==1){
		klj=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			klj=klj&a[i];
		}
		cout<<klj;
		return 0;
	}
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>=cnt[30-i]){
				a[j]-=cnt[30-i];
				b[j][30-i+1]++;
				c[30-i+1]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			d[i]+=c[j]*b[i][j];
		}
		aa[i].first=d[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<d[i]<<" ";
//		for(int j=30;j>=1;j--){
//			cout<<b[i][j];
//		}
//		cout<<endl;
//	}
	sort(aa+1,aa+1+n,cmp);
	klj=aa[1].second;
	for(int i=2;i<=m;i++){
		klj=klj&aa[i].second;
	}
	cout<<klj;
	return 0;
}
