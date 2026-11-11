#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010],ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	int ans[200010]={0};
	if(n<=5&&m<=2){
		for(int i=1;i<=n;i++){
			int k=n-i+1,j=i,cnt=1;
			while(k--){
				b[cnt]=a[j];
				bool f=0;
				for(int w=1;w<=cnt;w++){
					if(b[w]==b[cnt]){
						f=1;
					}
				}
				if(f==1){
					for(int w=1;w<=n;w++){
						b[w]=0;
					}
					cnt=1;
					b[1]=a[j];
				}
			}
			bool x=0,y=0;
			for(int w=1;w<=cnt;w++){
				if(b[w]==1&&x==0){
					ans[1]++;
					x=1;
				}else{
					if(b[w]==2&&y==0){
						ans[2]++;
						y=1;
					}
//					ans[2]++;
				}
			}
		}
		cout<<ans[1]<<' '<<ans[2];
	}
	return 0;
}

