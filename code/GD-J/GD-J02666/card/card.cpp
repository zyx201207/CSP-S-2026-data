#include<iostream>
#include<cstring>

using namespace std;


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;//a原牌数，b点数种类
	int num[100000] = {};
	cin>>a>>b;
	for(int i = 0;i<a;i++){
		int y;
		cin>>y;
		num[i] = y;
	}
	int sum[100000] = {};
	for(int i = 0;i<a;i++){//牌局轮数
		int card[100000]={},table[100000]={};
		for(int j = i;j<a;j++){//单局回合
			int state = num[j];//当局判断第i个数字
			//card[j-1] = num[j];
			bool flag = 0;
			long long keep = 0;
			for(int k = 0;k<j-i;k++){//判断牌是否出现牌局中
				if(table[k] == state){
					flag++;
					keep = k;
					break;
				}
			}
			if(flag==1){//是
				for(int k = keep;k<a;k++){
					table[k] = 0;
				}
			}
			for(int k = 0;k<a;k++){
				if(table[k] == 0){
					table[k] = state;
					break;
				}
			}
		}
		for(int j = 0;j<a;j++){
			sum[table[j]-1]++;
		}
	}
	for(int i = 0;i<b;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
