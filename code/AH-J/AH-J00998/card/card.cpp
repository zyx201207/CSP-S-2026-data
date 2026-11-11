#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],t,b[300005],z[500005],s[300005];
int mian(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	t=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t=1;
		for(int j=1;j<=m;j++) b[i]=0;
		for(int j=1;j<=500000;j++) z[i]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0) z[t]=a[j],b[a[j]]++,t++;
			else{
				int v=0;
				for(int k=1;k<=t;k++){
					if(z[k]==j) v=1;
					if(v==1) b[k]--,a[k]=0,v--;
				}
				z[t]=a[j],b[a[j]]++,t++;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=0) s[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
