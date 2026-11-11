#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const N=5e5+10,M=3e5+10;
ll a[N]{0};
ll n,m;
ll ans_[N]{0};
int main(){
	//freopen("cards.in","r",stdin);
	//freopen("cards.out","w",stdout);
	//ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(ll i_=1;i_<=n;i_++){
		
		cin>>a[i_];
		
	}
	
	for(ll j=1;j<=n;j++){
	
	ll cnt_[N]{0};	//记录每张牌，每次开始新一局时清空桌子和记录器 
	ll size=1;		//牌数 
	ll table[N]{0};	//桌子 
	for(ll i=j;i<=n;i++){
		
		if(cnt_[a[i]]==0){
			//没有相同的排就放 
			table[size]=a[i];
			
			size++;
			
			cnt_[a[i]]=size;	//面额为a[i]的牌放在i  
		}else{			
			//有相同的就丢 
			ll abc_=size;
			size=cnt_[a[i]];
			cnt_[a[i]]=0;//弃牌 
			
		}
	}
	//结束
	for(ll i=1;i<=m;i++){
		if(cnt_[i]!=0){
			ans_[i]+=cnt_[i]; 
		}
	}
	
	}
	
	for(ll i=1;i<=m;i++){
		//输出牌数 
		cout<<ans_[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
