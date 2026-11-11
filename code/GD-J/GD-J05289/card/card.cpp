#include<bits/stdc++.h>
using namespace std;
int q[500022];
int a[500043]; // 纸牌
int b[300022]; //出现次数 
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(b, 0, 300022);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int k = 1; k <= n; k ++){
		memset(q, 0, 500022);
		int num = 0; //当前桌上牌数 
		for(int i = k; i <= n; i ++){
			if(num == 0){
				q[0] = a[i];
				num ++;
//				cout << "0 ";
				continue;
			}
			bool same = false; //判断此前是否有点数为ai的牌 
			int pos = 0;
		    for(int j = 0; j < num; j ++){
		    	if(same == true){
		    		q[j] = 0;
		    		continue;
				}
			    if(same == false && q[j] == a[i]){ //有 
			    	q[j] = 0;
			    	same = true;
			    	pos = j + 1;
				}
		    }
		    num = num - pos;
		    q[num] = a[i];
		    num ++;
//		    cout << pos << " ";
//		    for(int j = 0; j < num; j ++){
//	    	    cout << q[j] << " ";
//		    }
//		    cout << endl;
		    
	    } //出牌结束 
//	    cout << endl;
		
	    for(int i = 1; i <= m; i ++){
	    	for(int j = 0; j < num; j ++){
	    		if(q[j] == i){
	    			b[i] ++;
	    			break;
				}
			}
		}
	}
	for(int i = 1; i <= m; i ++){
		cout << b[i] << " ";
	}
	return 0;
}
