#include<bits/stdc++.h>
using namespace std;
int a[500010];
int c[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=i;j<=n;j++){
			if(lower_bound(c+i,c+t-1,a[j])!=upper_bound(c+i,c+t-1,a[j])){
				int pos=lower_bound(c+i,c+t-1,a[j])-c;
//				cout<<pos<<'\n';
				t=pos;
				for(int k=pos;k<=j;k++){
					c[k]=0;
				}
			}
			c[t++]=a[j];
		}
		for(int j=i;j<t;j++){
			ans[c[j]]++;
//			cout<<c[j]<<' ';
			c[j]=0;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
