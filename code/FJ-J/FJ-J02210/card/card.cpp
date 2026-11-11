#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005];
bool t[300005]={0},e[300005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1) {
	cout<<n;
	return 0;
}
	for(int i=1;i<=n;i++){
		t[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(t[a[j]]==1){
				for(int d=i;d<j;d++){
					if(a[d]==a[j]&&e[d]==e[j])
				for(int k=c[d];k<j;k++){
					t[a[k]]=0;
					e[j]=0;
				}
			}
			}
			t[a[j]]=1;
			c[j]=j;
			e[j]=1;
		}
	    for(int j=1;j<=m;j++){
	    	if(t[j]==1) b[j]++;
		}
		for(int j=1;j<=m;j++) t[j]=0;	
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
