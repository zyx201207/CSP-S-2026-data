#include<bits/stdc++.h>
#define int long long
#define lc k<<1
#define rc k<<1|1
using namespace std;
int n,m;
int a[500005];
int b[500005];
int las[500005];
int cur=0,cnt[500005],ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
//	else if(m==2){
//		
//	}
	for(int i=1;i<=n;i++){
		cur=0;
		memset(cnt,0,sizeof(cnt));
		memset(las,0,sizeof(las));
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			b[++cur]=a[j];
//			cout<<cur<<"\n";
			if(cnt[a[j]]>1){
				for(int k=las[a[j]];k<=i;k++)cnt[a[k]]--;
//				if(cur==2){
//					cur=1;
//					continue;
//				}
				int l=1,r=cur-1,x=1;
				while(l<=r){
					int mid=l+r>>1;
					if(b[mid]==a[j]){
						x=mid;
						break;
					}
					else if(b[mid]<a[j]){
						l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
				cur=x;
			}
			las[a[j]]=j;
		}
		for(int j=1;j<=cur;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
