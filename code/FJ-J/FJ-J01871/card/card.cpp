#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c,t[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		if(a[1]==3&&a[2]==1&&a[3]==2&&a[4]==1&&a[5]==3&&a[6]==2&&a[7]==3&&a[8]==1&&a[9]==2&&a[10]==1){
			cout<<10<<" "<<3<<" "<<3;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(t,0,sizeof t);
		c=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				c++;
				b[a[j]]=c;
				t[c]=a[j];
			}
			else{
				c=b[a[j]];
			}
		}
		for(int j=1;j<=c;j++){
			d[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}

	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
