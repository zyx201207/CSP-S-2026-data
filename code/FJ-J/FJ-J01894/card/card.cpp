#include<bits/stdc++.h>
using namespace std;

int a[500005],ans[300005],cnt[300005],b[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	bool flag=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	} 
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		memset(b,0,sizeof(b));
		int sum=0;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0||cnt[a[j]]>sum){
				sum++;
				b[sum]=a[j];
				cnt[a[j]]=sum;
			}else{
				sum=min(sum,cnt[a[j]]);
			}
//			cout<<b[sum]<<" "<<sum<<"    ";
		}
		for(int j=1;j<=sum;j++){
//			cout<<b[j]<<" ";
			ans[b[j]]++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

