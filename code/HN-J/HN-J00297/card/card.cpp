#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005],b[2000005],c[2000005];
int x,y,z,bs;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bs=n;//赋值 
	while(bs--){
		x++;//记录跳过几张牌 
		z=0;
		for(int i=1;i<=100;i++)//初始化 
			b[i]=0;
		for(int i=x;i<=n;i++){
			y=0;
			for(int j=1;j<=n;j++) //记录有没有相同的牌 
				if(b[j]==a[i]) y=j;//记录编号 
			if(y==0){//无相同 
				z++;//放哪里 
				b[z]=a[i];
			}
			else{
				for(int j=y;j<=n;j++)//收牌 
					b[j]=0;
				z=0;
				for(int j=1;j<=n;j++)//判断有几张牌 
					if(b[j]>0) z++;
				z++;
				b[z]=a[i];
			}
				
		}
		for(int i=1;i<=n;i++){
			if(b[i]>0) c[b[i]]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
		
	return 0;
}

