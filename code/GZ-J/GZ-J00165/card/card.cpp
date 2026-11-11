//GZ-J00165 遵义市第四初级中学 聂宇东
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],cnt[m+1];
	fill(cnt,cnt+m+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	int q[n+1],t=0;
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			if(t==0)q[t++]=a[j];
			else{
				for(int z=0;z<t;z++)if(q[z]==a[j])t=z;
				q[t++]=a[j];
			}
		}
		for(int j=0;j<t;j++)cnt[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

