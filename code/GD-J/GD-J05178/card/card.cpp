#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		r=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<r;k++){
				if(b[k]==a[j]) r=k;
			}b[r++]=a[j];
		}for(int j=0;j<r;j++)c[b[j]-1]++;
	}for(int i=0;i<m;i++)cout<<c[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

