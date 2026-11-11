#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[500010],cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sym=1;
		for(int j=i;j<=n;j++){
			cnt[sym]=a[j];
			int s=a[j];
			int b=0;
			for(int k=1;k<sym;k++){
				if(cnt[k]==s&&k!=j){
					b=k;
					break;
				}
			}
			if(b>0){
				for(int h=1;h<sym;h++){
					cnt[h]=0;
				}
				cnt[1]=a[j];
				sym=1;
			}
			for(int c=1;c<=sym;c++){
				ans[cnt[c]]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
} 
