#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			bool f=0;
			for(int k=i;k<j;k++){
				if(a[j]==b[k]){
					f=1;
					for(int t=k;t<j;t++) b[t]=0;
					b[j]=a[j];
				}
			}
			if(f==0) b[j]=a[j];
		}
		for(int j=i;j<n;j++){
			if(b[j]!=0){
				//cout<<b[j]<<' ';
				t[b[j]]++;
			}
		}
		//cout<<endl;
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<' ';
	return 0;
}
