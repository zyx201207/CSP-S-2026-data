#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string table=" ";//桌上的牌 

int a[500010];//记录手中牌的顺序 

int b[300010];//统计多少局结束时.... 

map<ll,ll> mp;//记录当前种类的牌出现位置 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	//输入打的牌 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//从第一张牌开始游戏 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){		
			//如果前面放过了
			if(mp.count(a[j])){
				string writable = table.substr(mp[a[j]],table.size());//记录清除的牌是什么 
				if(writable.size()<table.size()){
					string tex1=table.substr(1,mp[a[j]]);//清除桌面该牌右边的牌，保留左边 
					table = " "+tex1;
				}
				else{
					table = " ";
				}
				
				for(auto k:writable){
					int jc = k-'0';//牌是什么点数 
					mp.erase(jc);//擦去记录的位置，通过键 
					b[jc]--;//此时这局不存在这个牌 
				}
				mp[a[j]]=table.size();//记录新放的牌的位置 
				b[a[j]]++;//此局存在这个牌 ,++
			}
			//没放过就照常记录 
			else{
				mp[a[j]]=table.size();
				b[a[j]]++;
			}
			//放牌	
			string ca = to_string(a[j]);
			table+=ca;		
		}
		
		table = " ";//新一局开始，清空桌面 
		mp.clear();//放牌位置也清空 
	}
	
	//所有局结束后，输出结果 
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
