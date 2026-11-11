#include <bits/stdc++.h>
using namespace std;
int a[500010];
int aa[500010];
int cc[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){		//输入 
		cin >> a[i];
	}
	int u=0; 
	for(int i=1;i<=n;i++){		//第i局 
		for(int j=1;j<=i-1;j++){	//删除跳过的牌 
			aa[j]=0;
		}
		for(int l=1;l<=n;l++){		//第l次出牌 
			for(int k=0;k<n;k++){		//遍历判断是否有k 
				if(aa[k]!=a[l]){	//无 
					aa[u] = a[l];
					u++;
				}
				else{				//有 
					for(int o=k;o<u+1;o++){	 //删除这个数以及后面的数 
						aa[o] = 0;
					}
				}
			}
		} 
		for(int j=0;j<u;j++){	//每一轮的计数 
			if(aa[j]!=0){
				cc[aa[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){		//输出每个数字的个数 
		cout << cc[i] << " ";
	}
	return 0;
}
