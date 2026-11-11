#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],k[300005],op,u;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		op=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=op;
				op++;
			}else{
				u=0;
				for(int l=1;l<=m;l++){
					if(b[l]>b[a[j]]){
						//cout<<i<<' '<<l<<' '<<b[l]<<'|'<<endl;
						b[l]=0;
						u++;
					}
				}
				//cout<<op<<endl;
				for(int l=1;l<=m;l++){
					if(b[l]>b[a[j]]){
						b[l]-=u;
					}
				}
				
				op-=u;
				b[a[j]]=op-1;
			}
			//for(int l=1;l<=m;l++){
			//	if(b[l]!=0){
			//		//cout<<i<<' '<<l<<' '<<b[l]<<'|';
			//	}
			//}
			//cout<<endl;
		}
		for(int l=1;l<=m;l++){
			if(b[l]!=0){
				//cout<<i<<' '<<l<<'|';
				k[l]++;
				b[l]=0;
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<' ';
	}
	return 0;
}
