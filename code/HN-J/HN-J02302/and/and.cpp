#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000000],y=1,x;
int maxn[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m%2==0){
		y=0;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j]%2==y&&a[j]!=-1){
				if(a[j]>maxn[i]){
					maxn[i]=a[j];
					x=j;
				}
			}
		}
		a[x]=-1;
	}
	int e=maxn[0];
	for(int i=1;i<m;i++){
		e&=maxn[i];
	}
	cout<<e;
	return 0;
}
