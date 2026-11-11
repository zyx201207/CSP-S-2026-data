#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005],nn[300005],mm[300005]={0},l=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		l=i;
		for(int j=l;j<n;++j){
			for(int k=0;k<sizeof(nn);++k){;
				if(a[j]==nn[k]){
					for(int h=k;h<=j;++k)a[h]=0;
				}
				else nn[k]=a[j];
			}
		}
		for(int g=l;g<n;++g){
			for(int f=1;f<=m;++f){
				if(a[g]==f)mm[f]++;
			}
		}
	}
	for(int i=1;i<=m;++i)cout<<mm[i]<<endl;
	
}
