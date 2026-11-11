//马辰一帆 GZ-J00578 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
int card[500005],cishu[300005],table[500005],n,m,shunxu=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int d=1;d<=shunxu;d++){
				if(table[d]==card[j]){
					for(int h=d;h<=shunxu;h++){
						table[h]=0;
						shunxu--;
					}
					break;
				}
				
			}
			shunxu++;
			table[shunxu]=card[j];
		}
		for(int s=1;s<=shunxu;s++){
			cishu[table[s]]++;
		}
	}
	for(int i=1;i<n;i++){
		cout<<table[i]<<' ';
	}
	return 0;
}	
//hymmyyds
