#include<bits/stdc++.h>
using namespace std;
int p[500005];
int ans[300005];
int st[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int k=1,top;
	while(k<=n){
		//cout<<"///////第"<<k<<"局游戏//////"<<endl; 
		//新开一局游戏 栈更新 
		top=0;
		//无视前面的元素 从k开始 
		for(int i=k;i<=n;i++){
			int f=-1;
			//往前找 看能不能收网 
			for(int j=1;j<=top;j++){
				//cout<<"p[i]= "<<p[i]<<" st[j]= "<<st[j]<<endl;
				if(p[i]==st[j]){
					//cout<<endl<<"FIND FIND FIND"<<endl;
					f=j;//找到了 标记位置 
					break;
				}
			}
			if(f!=-1){
				//找到了就收网 top更新为上一个重复的点数的位置 
				top=f;
			}else{
				//没找到就入栈 
				st[++top]=p[i];
			}
//			cout<<"//////////"<<endl;
//			for(int i=1;i<=top;i++){
//				cout<<st[i]<<" ";
//			}cout<<endl<<"top= "<<top<<endl<<"///////////"<<endl;
		}
		k++;
		//此时栈中元素即为桌上的牌 
		for(int i=1;i<=top;i++){
			//cout<<st[i]<<" ";
			ans[st[i]]++;
		}//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*

4 3
1 2 1 3
//3 1 4

10 3
3 1 2 1 3 2 3 1 2 1
//10 3 3

*/
