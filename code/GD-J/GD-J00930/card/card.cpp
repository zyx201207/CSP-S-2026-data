#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p[500010],ans[300010];
	cin>>n>>m;
	for(int i=1;i<=m;i++) ans[i]=0;
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n-1;i++){
		int a[500010]={},b[500010];
		for(int j=0;j<n;j++) b[j]=0;
		for(int j=i;j<n;j++){
			int f=0;
			for(int k=0;k<a.size();k++){
				if(a[k]==p[j]){
					f=1;
					break;
				}
			}
			if(f){
				for(int k=j+1;k<a.size();k++) a[k]=0;
			}
			a[a.size()]=p[j];
		}
		for(int j=0;j<a.size();j++) b[a[j]]=1;
		for(int j=0;j<b.size();j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
