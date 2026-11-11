#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005],num[500005],ans[500005];
int lst[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){//每一轮 
		int cnt=0;
		memset(lst,0,sizeof(lst));
		memset(num,0,sizeof(num));
		for(int j=i;j<=n;j++){
			if(lst[arr[j]]<=cnt && lst[arr[j]]!=0){
				cnt=lst[arr[j]];
			}else{
				if(num[++cnt] && lst[num[cnt]]==cnt){
					lst[num[cnt]]=0;
				}
				lst[arr[j]]=cnt;
				num[cnt]=arr[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[num[j]]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
yiwugougou，是我赢了
出题人，恕我直言，我没有看出你哪里赢了
爱卿请看，我的T4让你想出了O(nm)的做法，打完之后调了30min才发现是错解，然后写了O(N^2)做法，是我赢了
我***********ccf（已被yiwugougou和谐）（此处yiwugougou开心到飞起来） 

快买保分符！！！ 
*/
