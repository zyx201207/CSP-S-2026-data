#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[300005]={},a[500005]={},n,m,ta=0,f=0,t[500005]={};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<2){
		cout<<n;return 0;	
	} 
	if(m==2){
		int c1=0,c2=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i]==1) c1=1;
				if(a[i]==2) c2=1;
				if(c1&&c2)break;
			}
			c[1]+=c1;c1=0;
			c[2]+=c2;c2=0;
		}
		cout<<c[1]<<" "<<c[2];
		return 0;	
	}
	for(int z=1;z<=n;z++){
		for(int i=z;i<=n;i++){
			for(int j=1;j<i;j++){
				if(t[j]==a[i]){
					f=1;
					ta=j-1;
					t[j]=0;
					continue;
				}
				if(f==1){
					t[j]=0;
				}
			}
			if(f==1){
				f=0;
			}
			ta++;
			t[ta]=a[i];
		}
		for(int b=1;b<=ta;b++){
			c[t[b]]++;
		}
		ta=0;
		memset(t,0,sizeof(t));
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}

