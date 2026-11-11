#include <bits/stdc++.h>
using namespace std;
long long n, m, nengliang[500010];
int chazhi[500010];
//queue<int> Q;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "W", stdout);
    cin >> n >> m;;
    for(int i = 0; i < n; i++){
		cin >> nengliang[i];
	}
	if(m > 1000000000){
		int ans = 0, jian = nengliang[1] - nengliang[0], shumu = 1;
		while(m > 0 && shumu <= n){
			if(m >= shumu * jian){
				m -= shumu * jian;
				shumu++;
				ans++;
			}
			else{
				m = 0;
			}
		}
		cout << ans << endl;
		return 0;
	}
	else {
		sort(nengliang, nengliang + n);
		int xiao = 100001, cong[5005] = {0}, congzong = 0, anszan = 0, ans = 0;//xiao表示最小差值 cong表示最小差值的坐标1`n,congzong表示一共几个最小差值，anszan表示暂时答案，ans表示最终答案
		for(int i = 1; i < n; i++){
			chazhi[i] = nengliang[i] - nengliang[i-1];
			if(xiao == chazhi[i]){
				cong[congzong] = i;
				congzong++;
			}
			else if(xiao > chazhi[i]){
				cong[0] = i;
				congzong = 1;
			}
		}
		for(int i = 0; i < congzong; i++){
			anszan = 1;
			long long m0 = m;//m0表示还能操作几次
			//Q.push(cong[i]);
			int zuo = cong[i] - 1, you = cong[i] + 1, dangqianshumu =  1;//当前坐标和一起变化的宝石数目//表示当前可以操作的左右坐标1，n
			while(/*!Q.empty()*/m0 >= 0){
				/*int dang = Q.front(), */
				//Q.pop();
				if(zuo > 0 && zuo < n){
					if(you > 0 && you < n){//左右正常
						if(dangqianshumu * chazhi[you] > chazhi[zuo]){
							anszan++;
							if(m0 >= chazhi[zuo]){
								m0 -= chazhi[zuo];
							}
							else{
								break;
							}
							zuo--;
							dangqianshumu ++ ;
						}
						else{
							anszan++;
							if(m0 >= chazhi[you]){
								m0 -= chazhi[you];
							}
							else{
								break;
							}
							you++;
							dangqianshumu ++ ;
						}
					}
					else{//左正右异
						anszan++;
						if(m0 >= chazhi[zuo]){
							m0 -= chazhi[zuo];
						}
						else{
							break;
						}
						zuo--;
						dangqianshumu ++ ;
					}
				}
				else if(you > 0 && you < n){//左异右正
					anszan++;
					if(m0 >= chazhi[you]){
						m0 -= chazhi[you];
					}
					else{
						break;
					}
					you++;
					dangqianshumu ++ ;
				}
				else{//都异
					break;
				}
			}
			ans = max(anszan, ans);
		}
		cout << ans << endl;
	}
    
    
    
    
    
    return 0;
}
