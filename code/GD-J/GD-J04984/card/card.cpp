#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],cnt,cnt1[500005],cnt2[500005],cnt3;
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	memset(cnt2,-1,sizeof(cnt2));
	for(int i=1;i<=n;i++){
		if(i==1)cnt=a[i];
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt2[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(cnt==i){
			cout<<n-cnt2[i]+1<<" ";
		}
		else if(i==2){
			cout<<1<<" ";
		}else{
			cout<<n-cnt2[i]<<" ";
		}
	}
	return 0;
} 
