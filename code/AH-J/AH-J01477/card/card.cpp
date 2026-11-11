#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],s[500005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt[500005]={0};
		for(int j=1;j<=n;j++){
			cnt[a[j]]++;
		}
		for(int j=1;j<=n;j++){
			if(cnt[a[j]]>=2){
				if(cnt[a[j]]%2==0)s[a[j]]-=cnt[a[j]]/2;
				else s[a[j]]-=(cnt[a[j]]-1)/2-1;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					for(int l=j+1;l<k;l++)s[a[l]]--;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]!=0)s[a[j]]++;
		}
		a[i]=500005;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
} 
