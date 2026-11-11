#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
void nd(int x,int y){
	if(a[x]==a[y]){
		for(int i=y;i<=x-1;i++){
			b[i]=0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mm[300010];
	for(int i=1;i<=m;i++){
		mm[i]=0;
		b[i]=0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=n+1;
	while(n--){
		for(int i=w-n;i<=w-1;i++){
			b[i]=a[i];
		}
		for(int i=n;i>=w-n+1;i--){
			for(int j=i-1;j>=1;j--){
				nd(i,j);
			}
		}
		for(int i=w-n;i<=w-1;i++){
			for(int j=1;j<=m;j++){
				if(b[i]==j&&mm[j]<=w-n-1){
					mm[j]++;
				}
			}
		}
			
	}
	for(int i=1;i<=m;i++){
		if(mm[i]>=w-1){
			mm[i]=w-1;
		}
		cout<<mm[i]+1<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
