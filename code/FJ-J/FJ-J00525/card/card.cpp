#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],c[M],ans[M];//c´æÏÂ±ê 
void cl(int k,int en){
		for(int i=k;i<=en;i++){
			c[a[i]]=0;
		}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cl(1,n);
		for(int j=i;j<=n;j++){
			if(c[a[j]]>0){
				cl(c[a[j]],j);
			}
				c[a[j]]=j;
			}
		
	    /*for(int j=1;j<=m;j++){
			cout<<c[j]<<" ";
		}
		cout<<endl;
		 */
		 
		for(int j=1;j<=m;j++){
			if(c[j]>0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}



