#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],rt[500005],bk[300005];
long long cnt[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		rt[i]=bk[a[i]]=max(bk[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		cnt[i]++;
		ans[a[i]]+=cnt[i];
		cnt[rt[i]+1]+=cnt[i];
	}
	for(int i=1;i<m;i++){
		printf("%lld ",ans[i]);
	}
	printf("%lld",ans[m]);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

int n,m,a[500005],b[500005],bk[500005],ans[500005],h=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		h=1;
		for(int j=1;j<=m;j++) bk[j]=0;
		for(int j=i;j<=n;j++){
			if(bk[a[j]]){
				while(h>1&&a[b[h-1]]!=a[j]){
					bk[a[b[h-1]]]--;
					h--;
				}
				b[h-1]=j;
			}else{
				bk[a[j]]++;
				b[h]=j;
				h++;
			}
		}
		for(int j=1;j<h;j++){
			ans[a[b[j]]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

int n,m,a[500005],ans[500005],rt[500005],bk[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(bk[a[i]]){
			rt[i]=bk[a[i]];
			continue;
		}
		bk[a[i]]=i;
		rt[i]=-1;
	}
//	for(int i=1;i<=n;i++){
//		cout<<rt[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		int tmp=i;
		while(tmp<=n){
//			cout<<tmp<<' ';
			ans[a[tmp]]++;
			if(rt[tmp]==-1) tmp++;
			else tmp=rt[tmp]+1;
		}
//		cout<<endl;
	}
	for(int i=1;i<m;i++){
		printf("%d ",ans[i]);
	}
	printf("%d",ans[m]);
	return 0;
}
*/
