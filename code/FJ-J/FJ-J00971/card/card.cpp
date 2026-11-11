#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[500010],b[500010],c[500010],ans[500010];
bool now[500010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	l=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(now[a[i]]!=1){
				l++;
				b[l]=a[i];
				c[a[i]]=l;
				now[a[i]]=1;
				ans[a[i]]++;
			}else{
				for(int k=c[a[i]]+1;k<=l;k++){
					now[b[k]]=0;
					ans[b[k]]--;
				}
				l=c[a[i]];
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
