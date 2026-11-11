#include<bits/stdc++.h>
using namespace std; 
const long long N=2e5+10,M=3e5;
long long n,m;
long long a[N],ans[N];
long long pos[M];
long long sl[N],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(pos,0,sizeof pos);
		memset(sl,0,sizeof sl);
		t=0;
		for(int j=i;j<=n;j++){
			if(!pos[a[j]]){
				t++;
				sl[t]=a[j];
				pos[a[j]]=t;
			}else{
				for(int jn=pos[a[j]]+1;jn<=t;jn++){
					pos[sl[jn]]=0;
				}
				t=pos[a[j]];
			}
		}
		for(int j=1;j<=m;j++){
			if(pos[j]==0) continue;
			else ans[j]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
}
