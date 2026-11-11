#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005],to[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		to[a[i]]++;
	}
	
	int tmp=0;
	int maxn=INT_MIN;
	for(int i=0;i<n;i++){
		int jz=a[i],w=to[a[i]],lm=m;//jz是均值，w是最大数量，lm是临时操作步骤 
		for(int j=0;j<n;j++){
			ans[j]=jz-a[j];//每一个数要增加几步 
			if(ans[j]<0){
				ans[j]=0;
			}
		}//无问题 
//		for(int j=0;j<n;j++){
//			cout<<ans[j]<<" ";
//		}
		sort(ans,ans+n); 
		int q=0;
		while(lm>0){
			if(ans[q]!=0){
				w++;
				lm-=ans[q];
			//	cout<<"j ";
			}
			
			q++;
			if(q>=n){
				break;
			}
		}
		
//		cout<<endl; 
		maxn=max(maxn,w);
			
	}
	cout<<maxn;
	

	
	return 0;
}
