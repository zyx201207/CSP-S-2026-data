#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[300005],e[300005],m2[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int d[300005];
		for(int j=i;j<=n;j++){
			if(d[a[j]]==1){
			    for(int x=e[a[j]];x<=j-1;x++){
				    d[c[x]]=0;
				    c[x]=0;
			    }
		    }
		    c[j]=a[j];
		    d[a[j]]=1;
		    e[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			m2[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<m2[i]<<" ";
	}
	return 0;
}