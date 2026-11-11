#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 
LL n,m;//n：局数&牌堆牌数，m：牌的最大点数
char a[500005];//牌堆
LL b[300005];//每种牌在结束后的出现次数
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	
	string dk;//桌面
	for(LL i = 1;i <= n;i++) cin >> a[i];//牌堆输入
	 
	for(LL i = 1;i <= n;i++){
		dk = "";//清空桌面
		for(LL j = i;j <= n;j++){//跳过i-1张牌，打出牌
			char k = a[j];//当前打出的牌
			int pos = dk.find(k);
			if(dk.find(k) != string::npos) dk.erase(pos,dk.size() - pos + 1);//删除 
			dk += k;
		}
		for(LL j = 0;j < dk.size();j++) b[dk[j]-48]++;//记录 
	}
	for(LL i = 1;i <= m;i++) cout << b[i] << " ";
	return 0;
}
