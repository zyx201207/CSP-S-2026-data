#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],q[500005],b[500005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++)a[j]=b[j];
    	for(int j=i;j<=n;j++){
			q[j]=a[j];
    		for(int k=i;k<j;k++){
    			if(q[k]==q[j]){
    				for(int d=k+1;d<=j;d++)q[d]=0;
    				break;
				}
			}
		}
		
    	for(int j=i;j<=n;j++)cout<<q[j];
    	cout<<"\n";
    	for(int j=i;j<=n;j++){
    		t[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}

