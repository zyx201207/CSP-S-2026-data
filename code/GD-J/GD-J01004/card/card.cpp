#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int c[300050],c2[300050];
int a2[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
//	map<int,int> mp;
bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
//	if(f==0){
//		for(int o=1;o<=n;o++){
//			c2[a[o]]++;
//		}
//		for(int o=1;o<=m;o++){
//			if(c2[o]==1) c[o]=n;
//			else c[o]=1;
//		}
//		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
//		//return 0;
//	}
	//c[m]=n;
	for(int o=1;o<=n;o++){
		memset(c2,0,sizeof(c2));
		memset(a2,0,sizeof(a2));
		for(int i=o;i<=n;i++){
			c2[a[i]]++;
			a2[i]=a[i];
			if(c2[a[i]]>1){
				int p=0;
				for(int j=1;j<=n;j++){
					if(a2[j]==a2[i]) {
						p=j;
						break;
					}
				}
				for(int j=p;j<i;j++){
					c2[a[j]]=0;
					a2[j]=0;
				} 
				c2[a[i]]=1;
			}
		}
		for(int j=1;j<=m;j++){
		//	cout<<c2[j]<<" ";
		if(c2[j]>0) c[j]++;
			//c[j]+=c2[j];
		}
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
