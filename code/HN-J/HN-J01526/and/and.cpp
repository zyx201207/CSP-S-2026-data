#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int arr[200005],pre[200005],nxt[200005];
bool wei[200005][35];//wei[i][j]:对于第i个元素，他的二进制下第j位为0/1 
void del(int x){
	pre[nxt[x]]=pre[x];
	nxt[pre[x]]=nxt[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		int x=arr[i],cnt=0;
		pre[i]=i-1;
		nxt[i]=i+1;
		while(x){
			cnt++;
			if(x&1){
				wei[i][cnt]=1;
			}
			x>>=1;
		}
	}
	nxt[0]=1;
	pre[n+1]=n; 
	for(int j=30;j>=1;j--){
		int count=0;
		for(int i=nxt[0];i<=n;i=nxt[i]){
			if(wei[i][j]){
				count++;
			}
		}
		if(count>=m){
			for(int i=nxt[0];i<=n;i=nxt[i]){
				if(!wei[i][j]){
					del(i);
				}
			}
			ans|=(1<<(j-1));
		}
	}
	cout<<ans;
	return 0;
}
/*
差点AK，T4不会QWQ

关注yiwugougou谢谢汪 

****ccf（已被yiwugougou和谐）

算鸟，100+100+100+48=348（感觉会挂分）

学了两年半没有AK我是**吗QWQ 

AAA保分符批发，快买啊！！！ 
*/
