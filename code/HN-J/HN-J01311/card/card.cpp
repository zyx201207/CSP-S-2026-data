#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<+n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;i<=n;i++){
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					cnt=k;
					j=k;	
				}
			}
		}
		for(int j=cnt;j<=n;j++){
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
