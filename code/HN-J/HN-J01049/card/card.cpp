#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n,m,a[500005],b[500005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){ans=0;
		for(int j=1;j<=n;j++){
		b[j]=a[j];
	}
		for(int j=i+1;j<=n;j++){bool flag=true;
			for(int o=1;o<j;o++){
				if(b[j]==b[o])flag=false;
				if(flag==false)b[o]==0;
			}
		}
		for(int j=1;j<=n;j++){
		if(b[j]==i)ans++;
	}cout<<ans<<" ";
	}
	
	return 0;
}

