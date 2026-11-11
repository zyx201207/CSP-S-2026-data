#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[200005],k[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int p=1;
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				k[p]=a[i];
				p++;
				n--;
				i--;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			k[m]=(a[i]&a[j]);
			sort(k+1,k+1+m,cmp);
		}
	}
	cout<<k[m];
	
	return 0;
}
