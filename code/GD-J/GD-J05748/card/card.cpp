#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card2.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[n+5],ans[m+5]={0};
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++){//第i局时 
		for(int j=0;j<n;j++)b[j]=0;
		for(int j=i;j<n;j++)b[j]=a[j];//初始化b 
		
//		for(int j=0;j<n;j++)cout<<b[j]<<' ';
//		cout<<',';
		for(int j=i;j<n;j++){//第i局要从第i个开始 
			for(int k=i;k<j;k++){//剔除卡牌 
				if(b[k]==b[j]&&k<=j){
					for(int l=k;l<j;l++)b[l]=0;
					break;
				}
			}
		}
	
		for(int j=0;j<n;j++){//统计 
//			cout<<b[j]<<' ';
			if(b[j]>0)ans[b[j]-1]++;
		}
//		cout<<endl;
	}
	
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
