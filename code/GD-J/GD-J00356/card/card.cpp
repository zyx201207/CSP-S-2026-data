#include<bits/stdc++.h>
using namespace std;
int a[300005],b[500005],c[1000000];
int d[1000000];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		l=1;
		for(int j=i;j<=n;j++){
			if(d[b[j]]==0){
				c[l]=b[j];l++;
				d[b[j]]++;
			}
			else{
				while(l>=0){
					l--;
					if(c[l+1]==b[j]){
						l++;
						break;
					}
					d[c[l+1]]--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(d[j]>0) a[j]++;
			d[j]=0;c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
