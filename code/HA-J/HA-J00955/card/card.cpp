#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],s[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q[200005]={0},p=1;
		int t[100005]={0};
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				q[p]=a[j];
				p++;
				t[a[j]]=1;
			}else{
				while(p!=1){
					if(q[p]!=a[j]){
						t[q[p]]=0;
						q[p]=0;
						p--;
					}else{
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]==1){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}