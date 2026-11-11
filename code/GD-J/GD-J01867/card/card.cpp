#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],b[500005],p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			if(t[a[k]]==0)t[a[k]]=1,b[a[k]]=k;
			else {
				for(int j=b[a[k]]+1;j<k;j++){
					t[a[j]]=0,b[a[j]]=0;
				}
				t[a[k]]=1,b[a[k]]=k;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]==1){
				p[j]++;
			}
			t[j]=0,b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	
	return 0;
}
