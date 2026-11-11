#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
long long st[1000005];
long long cnt[1000005];
long long c=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) b[j]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				c++;
				st[c]=a[j];
				b[a[j]]=1;	
			}else{
				for(int k=c;k>=i;k--){					
					if(st[k]==a[j]){
						break;	
					}else{
						c--;
						b[st[k]]=0;						
					}
				}
				st[c]=a[j];
				b[a[j]]=1;				
			}	
		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				cnt[j]++;				
			}
		}		
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
