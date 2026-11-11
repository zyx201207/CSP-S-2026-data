#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int cnt;
int seat[500005],s[500005],now;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(++cnt<=n){
		memset(seat,0,sizeof(seat));
		memset(s,0,sizeof(s));
		now=0;
		for(int i=cnt;i<=n;i++){
			if(seat[a[i]]!=0){
				for(int j=seat[a[i]];j<=now;j++){
					seat[j]=0;
					s[j]=0;
				}
				now=seat[a[i]]-1;
				
			}seat[a[i]]=++now;
				s[now]=a[i];
		}
		for(int i=0;i<=now;i++)ans[s[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
