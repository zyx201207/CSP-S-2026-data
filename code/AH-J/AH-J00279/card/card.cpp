#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],k,l=1;
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	k=n;
	//A 7~9   a1<=a2<=...<=an
	while(k>1){
		int cnt=0;
		s="";
		for(int i=l;i<=n;i++){
			if(a[i]==a[i-1]){
				continue;
			}
			else{
				s+=(a[i]+'0');
				if(s.find(i+'0')){
					cnt++;
				}
			}
		}
		if(cnt!=0)	cout<<cnt<<" ";
		l++;
		k--;
	}
	return 0;
}
/*
他有一叠特制的纸牌,共有 n 张,从上到下的点数依次为a1,a2,...,an。
每张牌的点数都是1到m之间的整数,且每种点数都出现至少一次。

任意时刻桌面上同一种点数的牌至多只有一张
最后一张牌打出后,本局游戏结束

4 3
1 2 2 3



*/
