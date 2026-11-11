#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[200001],maxn=-1,maxm=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxm=maxn;
			maxn=a[i];
		}
		else if(a[i]>maxm){
			maxm=a[i];
		}
	}
	if(m==1){
		cout<<maxn;
	}
	int k=maxn&maxm;
	if(m==2){
		cout<<k;
	}
	fclose(stdin);
	fclose(stdout);
}
