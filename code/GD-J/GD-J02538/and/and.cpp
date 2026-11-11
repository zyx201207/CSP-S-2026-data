#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[32],b[200005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			cnt[j]+=((a[i]&(1<<j))!=0);
		}
	}
	int k;
	for(k=30;k>=0;k--)
		if(cnt[k]>=m)
			break;
	int j=0;
	for(int i=1;i<=n;i++){
		if(a[i]&(1<<k)){
			b[++j]=a[i];
		}
	}
	sort(b+1,b+j+1,cmp);
	int ans=b[1];
	for(int i=2;i<=m;i++){
		ans&=b[i];
	}
	cout<<ans;
	return 0;
} 
