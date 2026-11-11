#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],p[300005][2],k,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for(int j=i-1;j<=n;j++){
			if(p[a[j]][0]<1){
				k++;
				b[k]=a[j];
				p[a[j]][0]++;
				p[a[j]][1]=k;
			}else{
				for (int q=p[a[j]][1]+1;q<=k;q++){
					p[a[q]][0]=0;
					b[q]=0;
				}
				k=p[a[j]][1];
			}
		}
		for (int j=1;j<=m;j++){
			if (p[j][0]>0) ans[j]++;
		}
		memset(p,0,sizeof(p));
                k=0;
	}
        for (int i=1;i<=m;i++) cout<<(ans[i]-1)<<" ";
	return 0;
}
