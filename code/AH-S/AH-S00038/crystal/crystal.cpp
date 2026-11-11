#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		sort(a+1,a+n+1);
		int b[500010]={0};
		b[1]=1;
		//cout<<"into"<<endl;
	for(int i=2;i<=n;i++){
		b[i]=1;
		int u=m;
		int c[500010]={0};
		for(int j=1;j<=n;j++)c[j]=a[j];
		int j=i-1;
		while(j>=1){
				if(u<a[i]-c[j]){
					break;
					}
				u-=(a[i]-c[j]);
				c[j]+=a[i]-c[j];
				b[i]++;
				j--;
				//cout<<j<<' '<<u<<' '<<endl;
				}
				//cout<<endl;
		}
		//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
		//cout<<endl;
		sort(b+1,b+n+1);
		cout<<b[n];
return 0;
}
