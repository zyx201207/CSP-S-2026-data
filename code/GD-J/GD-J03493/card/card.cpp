#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[5005],l[5005],h[3005];
int book[3005],book2[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(h[a[i]]==0){h[a[i]]=i;continue;}
		l[i]=h[a[i]];
		h[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)book[j]=0;
		for(int j=i;j<=n;j++){
			if(i<=l[j]&&book[a[j]]){
				for(int k=l[j];k<=j-1;k++)book[a[k]]=0;
			}
			book[a[j]]=1;
		}
		for(int j=1;j<=m;j++)book2[j]+=book[j];
	}
	for(int i=1;i<=m;i++)cout<<book2[i]<<" ";
	return 0;
}
