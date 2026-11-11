#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000000],b[50000000],zhi=0,jie[10000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
		
		
		zhi=0;
		for(long long j=i;j<=n;j++){
			bool ming=false;
			for(long long is=1;is<=zhi;is++){
				if(b[is]==a[j]){
					ming=true;
					zhi=is;
					break;
					}
		}
	
		//	   for(int k1=1;k1<=zhi;k1++){
		//cout<<b[k1];
		
		//cout<<endl;
		//}
		if(ming==false){
		//	ha[a[j]]=true;
			//wei[a[j]]=j;
			b[++zhi]=a[j];
			//cout<<zhi<<" ";
			//for(int k1=1;k1<=zhi;k1++){
		//cout<<b[k1];
		//}
	//	cout<<endl;
			}
	}
	
	for(long long k=1;k<=zhi;k++){
		jie[b[k]]++;
		}
	//	cout<<endl<<endl<<endl<<endl;
}
	//cout<<cnt;
	for(long long k1=1;k1<=m;k1++){
		cout<<jie[k1]<<" ";
		}
    return 0;
}
