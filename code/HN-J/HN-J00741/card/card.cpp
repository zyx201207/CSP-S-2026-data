#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,s[300005],k[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int s1[300005]={0};
		for(int j=i;j<=n;j++){
			if(s1[a[j]]==1){
			//for(int t=1;t<=k[a[j]];t++) s1[a[t]]=0;
			for(int t=1;t<=m;t++) s1[t]=0;		
			}
			//k[a[j]]=j;
			s1[a[j]]++;
			//cout<<a[j]<<" ";//
		}
		for(int j=1;j<=m;j++) s[j]+=s1[j];
		//cout<<endl;//
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
	}
