#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(0));
		int l=0;
		for(int j=i;j<=n;j++){
			int f=0,ans=0;
			for(int k=1;k<=l;k++){
				if(f==1)b[k]=0,ans++;
				if(b[k]==a[j]){
					f=1;
					b[k]=0;
					ans++;
				}
			}
			l-=ans;
			b[++l]=a[j];
		}
		for(int k=1;k<=l;k++){
			c[b[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
