#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005],k,ji[500005],zk,tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];//输入 
	}
	
	for(int i=1;i<=n;i++){//模拟进行n局 
	
		for(int j=i;j<=n;j++){//每第i局独立 
			k=a[j];
			if(ji[k]==0){
				ji[k] = 1;//cunzai,wei0bucunzai
				b[j]=a[j];
			}else{
				for(zk=i;zk<=n;zk++)if(b[zk]==k)break;
				for(;zk<=j;zk++)b[zk] = 0;
				b[j] = a[j];
			}
			
		}
		
		//开始查找桶计数 
		for(int j=i;j<=n;j++){
			
			if(b[j]!=0){
				tong[b[j]]++;
				
			}
		}	
	}
	
	//所有处理结束，输出桶
	for(int i=1;i<=m;i++){
		if(tong[i] != 0)cout << tong[i] << " ";
	}
	
	return 0; 
}

