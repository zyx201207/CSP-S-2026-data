#include <bits/stdc++.h>

using namespace std;
int f(int x){
	int l=0;
	int a[10005],ans[10005];
	while(x){
		a[l++]=x%2;
		x/=2;
	}
	for(int i=0,j=l-1;i<l,j>=0;i++,j--){
		ans[i]=a[j];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int andn[m]={0};
	for(int i=0;i<m;i++){
		cin>>andn[i];
	}
	int maxand=0;
	sort(andn,andn+m);
	for(int i=m-1;i>=0;i--)if(andn[i]==andn[i-1])cout<<andn[i];return 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			int andm=f(andn[i])&(andn[j]);
			maxand=max(maxand,andm);			
		}	
	}
	cout<<maxand;
	return 0; 
}
