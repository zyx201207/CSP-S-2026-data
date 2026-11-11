#include<bits/stdc++.h>
using namespace std;
int const N=200009;
int a[N]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long maxn=0,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			int k=0;
			while(k<m){
				x=a[i]&a[j];
		     	k++;
			}
		}
		if(x>maxn)maxn=x;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
