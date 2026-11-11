#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int n,m;
int ans[500005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		memset(ans,0,sizeof(ans));
		int x=j-1;
		int len=0;
		while(x<=n){
			int flag=0;
			int num=0;
			x++;
			for(int i=1;i<=len;i++){
				if(ans[i]==a[x]){
					flag=1;
					num=i;
					break;
				}
			}	
			if(flag==0){
				len++;
				ans[len]=a[x];	
			}else{
				for(int i=num;i<=len;i++){
					ans[i]=0;
					len=num-1;
				}
				len++;
				ans[len]=a[x];
			}
		}
		for(int i=1;i<=len;i++){
			cnt[ans[i]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

