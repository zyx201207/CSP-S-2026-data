#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,cnt[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int b[500005]={0},x=i;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				b[a[j]]++;
				for(;x<j;x++) b[a[x]]--;
				x=j;
			} 
			b[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(b[j]>0) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
