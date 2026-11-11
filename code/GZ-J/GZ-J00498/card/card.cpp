//GZ-J00498 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000+50];//要出的牌 
int c[300000+50];//牌堆（已打出） 
int d[300000+50];//每种牌的位置 
int e[300000+50];//计数器 
int cnt=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int x=a[j];//点数 
			if(d[x]==0){ 
				c[cnt]=x;//牌堆有了这点数 
				d[x]=cnt;//存储这点数位置 
				cnt++;
			}else{
				for(int k=d[x]+1;k<cnt;k++){
					d[c[k]]=0;//这张牌位置没了 
					c[k]=0;//这个位置没有存牌 
				}
				c[cnt]=0;//新的牌向前提 
				cnt=d[x]+1;
			}
		}
		for(int j=0;j<cnt-1;j++){
			e[c[j]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<e[i]<<" ";
	}
	return 0;
}
