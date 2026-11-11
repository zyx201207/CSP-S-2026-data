#include<bits/stdc++.h>
using namespace std; 
int n,m,qq,b[300005];
int q[500005],x[500005];//x:桌面，q:牌堆 


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>q[i]; 
	
	for(int i=1;i<=n;i++){//第i局 
		qq=i;              //qq:即将要放牌的位置  
		for(int j=i;j<=n;j++){//打第j张牌  i~n 
			
			int v=qq; 
			for(int k=i;k<v;k++){//检查第k张牌是否重复ie q[j]  i~qq-1 
				if(x[k]==q[j]) //如果第k张牌重复 
				for(int l=k;k<v;k++){//清除第l张牌  k~qq-1 
					x[l]=0;
					qq--;
					//cout<<i<<"局，第"<<k<<"张重复，清除第"<<l<<"，qq："<<qq<<endl;
				}
			}
			
			//cout<<i<<"局，放第"<<j<<"张"<<"，qq："<<qq<<endl;
			x[qq]=q[j];//放 
			qq++;
		}
		
		
		for(int j=1;j<=m;j++){//判断是否有j   1~m 
			for(int k=i;k<qq;k++){//从i~qq-1检查 检查第k张  
				if(x[k]==j){
					b[j]++;
						//cout<<i<<"局，第"<<k<<"张有"<<j<<endl;
					break;//防重复 
				} 
			}
		}
		
		
		//for(int k=i;k<=n;k++){
		//	cout<<i<<"局，第"<<k<<"张是"<<x[k]<<endl;
		//}
		
		//memset(x,0,n+1);  //清空 
		for(int j=1;j<=n+1;j++){
			x[j]=0;
		}
	}
	
	
	for(int i=1;i<=m;i++){    //输 
		cout<<b[i]<<" ";      //出 
	}
	return 0;
}
