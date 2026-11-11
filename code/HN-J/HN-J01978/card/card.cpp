#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],k[300010];
int f(int i){
	int l[n+10],b[m+10]={};
	for(int o=i;o<=n;o++){
		l[o-i+1]=a[o];
	}
	for(int ii=1;ii<=n-i+1;ii++){
		if(b[l[ii]]!=0){
			for(int i1=b[l[ii]];i1<ii;i1++){
		        b[l[i1]]=0;
		        l[i1]=0;
	        }
		}
		b[l[ii]]=ii;
	}
	for(int j=1;j<=n-i+1;j++){
		if(l[j]!=0){
			k[l[j]]++;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
