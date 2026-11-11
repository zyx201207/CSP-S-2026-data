#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],nn,c[500005],num,ans[300005],x;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	nn=n;
	while(nn--){
		b[nn+2]=0;
		for(int i=1;i<=nn+1;++i)b[i]=a[i+n-nn-1];
		num=1;
		for(int i=1;i<=nn+1;++i){
			x=0;
			for(int j=1;j<num;++j){
				if(b[i]==c[j]){
					x=j;
					break;
				}
			}
			if(x==0){
				c[num]=b[i];
				num++;
			}
			else{
				for(int j=x+1;j<num;++j)c[j]=0;
				num=x+1;
			}
		}
		for(int i=1;i<num;++i)ans[c[i]]++;
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
