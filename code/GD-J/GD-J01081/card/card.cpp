#include<bits/stdc++.h>
using namespace std;
int n,m,ar[500010],t[300010],tt[300010],ttt[300010];
long long s,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=n;i>=1;i--){
		if(ttt[ar[i]]==0){
			tt[ar[i]]++;
			ttt[ar[i]]=i;
		}else{
			tt[ar[i]]--;
			tt[ttt[ar[i]]]++;
			ttt[ar[i]]=i;
		}
	} 
	for(int i=1;i<=m;i++){
		ans+=tt[i];
		cout<<ans<<" ";
	}
	return 0;
} 
