#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000000],b[100000000],c[10000000],m;
void hsy(int k){
	for(int i=k+1;i<=n;i++){
		for(int j=k;j<=i;j++){
			if(c[i]==c[j]&&c[i]!=0&&c[j]!=0&&i!=j){
				for(int p=j;p<i;p++) c[p]=0;
			}
		}
	}
	for(int j=k;j<=n;j++){
		if(c[j]!=0) b[c[j]]+=1;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) c[j]=a[j];
		hsy(i);
	}
	for(int i=1;i<=m;i++) if(b[i]!=0) cout<<b[i]<<" ";
	return 0;
}

