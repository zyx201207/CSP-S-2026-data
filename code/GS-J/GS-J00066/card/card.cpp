#include <bits/stdc++.h>
using namespace std;
bool flag[int(3*1e5+10)];
int a[int(5*1e5+10)];
int game[int(5*1e5+10)];
int idx,idx1;
int cnt[int(5*1e5+10)];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	
	for(int i=1;i<=n;i++){

			
		for(idx1=i;idx1<=n;idx1++){
			if(flag[a[idx1]]){
			
				while(game[idx]!=a[idx1]&&idx>0){
					
					game[idx]=0;
					idx--;
					if(idx<=0){
						
						
						game[1]=a[idx1];
						idx=1;
					}
				}
				
			}
			else{
				idx++;
				game[idx]=a[idx1];
				flag[a[idx1]]=true;
			}
		}
	
		while(idx>0){
			
			cnt[game[idx]]++;
			idx--;
			
		}
		for(int i=0;i<m;i++){
			flag[i]=false;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<< cnt[i]+1<<" ";
	}
	return 0;
}
