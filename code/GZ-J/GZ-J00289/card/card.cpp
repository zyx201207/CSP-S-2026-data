//GZ-J00289 周林学校 肖杭
#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005]={0},c[300005],d[300005]={0},f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
    	f=0;
    	for(int j=i;j<=n;j++){
    		f++;
			if(d[a[j]]==0){
				c[f]=a[j];
    		    d[a[j]]=f;
			}
			else f=d[a[j]];
		}
		for(int j=1;j<=m;j++)d[j]=0;
		for(int j=i;j<=f;j++){
			b[c[j]]++;
			cout<<c[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}


