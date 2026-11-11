#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				pos=j;
			}
		}
		if(pos==0){
			pos=1;
		}
		memset(c,0,sizeof(c));
		for(int j=pos;j<=n;j++){
			if(a[j]<=m&&c[a[j]]==0){
				b[a[j]]+=1;
				c[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==1){
			cout<<b[i];
		}else{
			cout<<" "<<b[i];
		}
	}
	cout<<"\n";
	return 0;
}
