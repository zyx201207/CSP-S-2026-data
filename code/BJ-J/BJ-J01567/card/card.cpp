#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int M=3e5+10;
int lst[M];
ll a[N],b[N];
int nxt[N],ls[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];//第i张卡牌的点数
		//lst[i]点数为i的上一张牌的编号
		//nxt[i]与第i张牌点数相同的下一张牌的编号
		if(lst[a[i]]!=0)ls[i]=lst[a[i]];//nxt[lst[a[i]]]=i
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int k=lst[i];
		while(ls[k]!=0){
			nxt[ls[k]]=lst[i];
			k=ls[k];
		}
	}
	for(int i=1;i<=n;i++)b[i]=1;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j])nxt[i]=j;
			continue;
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nxt[j]!=0){
				b[j]--;
				b[nxt[j]]++;
				j=nxt[j];
			}
		}
	}
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	for(int i=1;i<=m;i++){
		ll cnt=0;
		for(int j=1;j<=n;j++)if(a[j]==i)cnt+=b[j];
		cout<<cnt<<" ";
	}
	return 0;
}
