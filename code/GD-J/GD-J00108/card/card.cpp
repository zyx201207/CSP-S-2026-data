#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],d[5005],sum[5005],cnt=1,l[5005];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
			if(d[a[j]]==0){
				l[cnt]=a[j];
				d[a[j]]=cnt;
				cnt++;
			}
			
			else{
				long long suu=0;
				for(int k=d[a[j]];k<=cnt;k++){
					d[l[k]]=0;
					l[k]=0;
					suu++;
				}
				cnt-=suu;
				l[cnt]=a[j];
				d[a[j]]=cnt;
				cnt++;
			}
			
		}
		for(int j=1;j<=cnt;j++){
			sum[l[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<endl;
	}
	
	return 0;
}
