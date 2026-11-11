#include <bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005];
bool f[500005];
int k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			k[a[i]]++;
			bool flag=0;
			for(int z=i;z<j;z++){
				if(flag=1){
					k[a[z]]--;
					f[z]=0;
				}
				if(a[z]==a[j] && f[z]){
					k[a[z]]--;
					f[z]=0;
					flag=1;
				}	
			}
		}
		for(int j=i;j<=n;j++){
//			cout<<k[a[i]]<<endl;
			if(k[a[i]]>0){
				cnt[a[i]]++;
			}
		} 
		memset(f,true,n);
		memset(k,0,m);
	}
	for(int i=1;i<=m;i++){
		if(i!=m){
			cout<<cnt[a[i]]<<" ";
		}
		else{
			cout<<cnt[a[i]];
		}
	}
}
