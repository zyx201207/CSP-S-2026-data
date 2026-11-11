#include<bits/stdc++.h>
using namespace std;
int n,m,now=0;
int ans[500005],a[500005],leave[500005],dk[500005],s[500005];
//strack<int> 
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	while(++cnt!=n){
		memset(dk,0,sizeof(dk));
		memset(s,0,sizeof(s));
		now=0;
		for(int i=cnt;i<=n;i++){
			if(dk[a[i]]!=0){
				for(int j=dk[a[i]];j<=now;j++){
					dk[j]=0;
					s[j]=0;
				}
				now=dk[a[i]]-i;
				
//				dk[a[i]]=0;
			}
			else{
				s[a[i]]=++now;
				s[now]=a[i];
			}
		}
		for(int i=1;i<=now;i++){
			ans[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
