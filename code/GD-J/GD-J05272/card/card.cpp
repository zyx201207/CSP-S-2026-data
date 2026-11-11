#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n,m,a[100005],p[1005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int b[100005]={0};
		int c[1005][2]={0};
		for(int j=i;j<n;j++){
			b[j]=a[j];
			c[b[j]][0]++;
			if(c[b[j]][0]==2){
				c[b[j]][0]=1;
				for(int l=c[b[j]][1];l<j;l++){
					b[l]=0;
					c[b[l]][0]--;
				}
			}
			c[b[j]][1]=j;
		}
		for(int j=i;j<n;j++){
			if(b[j]!=0){
				p[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<' ';
	} 
	return 0;
}
