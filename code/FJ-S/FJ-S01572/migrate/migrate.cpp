#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000006],mx[2000006],ans,num;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			mx[i]=0;
			for(int j=i+1;j<n;j++){
				mx[j]=0;
				if(x[j]-x[i]<=d){
					mx[j]=1; 
				}
				else{
					num=0;
					for(int k=j-1;k>i;k--){
						if(mx[k]==0){
							break;
						}
						//cout<<' '<<j<<' '<<k<<' '<<num<<endl;
						if(x[j]-x[k]<=d){
							if(mx[j]>mx[k]+1||mx[j]==0){
								num=1;
								mx[j]=mx[k]+1;
							}
							else if(mx[j]==mx[k]+1||mx[j]!=0){
								num++;
							}
						}
						else{
							break;
						}
					}
					if(num==2&&mx[j]!=0){
						//cout<<i<<' '<<j<<' '<<mx[j]<<endl; 
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
