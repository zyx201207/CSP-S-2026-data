#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10,MAXM=3e5+10;
int n,m;
int a[MAXN];
int fir[MAXM];
int ans[MAXM];
int c[MAXN];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int idx=0;
		memset(fir,0xff,sizeof(fir));
		for(int j=i;j<n;j++){
			if(fir[a[j]]==-1){
				fir[a[j]]=idx;
				c[idx++]=a[j];
			}
			else{
				for(int k=fir[a[j]]+1;k<idx;k++) fir[c[k]]=-1;
				idx=fir[a[j]]+1;
			}
		}
		for(int j=1;j<=m;j++){
			if(fir[j]!=-1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}
