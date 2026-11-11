#include<bits/stdc++.h>
#define N 500010
#define M 300010
using namespace std;
int n,m;
int  a[N];
bool b[M];//是否在桌上 
int  c[N],cnt;//桌
int ans[M];

bool A=1;//是否满足特殊性质 

//纯模拟 

void son(int x){//从第x张牌开始进行一次游戏 
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	cnt=0;
	for(int i=x;i<=n;i++){
		int card=a[i];
		if(b[card]>0){
			while(c[cnt]!=card){
				b[c[cnt]]=0;
				cnt--;
			}
		}else{
			b[card]=1;
			c[++cnt]=card;
		}
	}
	
	for(int i=1;i<=cnt;i++){
		ans[c[i]]++;
	}
}

void steal(){
	int last=a[1];
	int cnt=1,lc=0;
	for(int i=2;i<=n;i++){
		if(a[i]==last)cnt++;
		else{
			last=a[i];
			lc+=cnt;
			cout<<lc<<' ';
			cnt=1;
		}
	}
	cout<<lc+cnt<<' ';
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])A=0;
	}
	if(A){
		steal();
		return 0;
	}
	for(int i=1;i<=n;i++){
		son(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

