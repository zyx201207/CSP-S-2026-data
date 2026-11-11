#include<bits/stdc++.h>
using namespace std;
int q[10000100],s[100100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[101000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[1000001]={};
		int b=i;
		for(int j=i;j<=n;j++){
			if(q[a[j]]==0){
				t[j-b+1]=a[j];
				q[a[j]]++;
			}else{
				for(int k=i;k<j;k++){
					q[a[k]]=0;
				}
				t[1]=a[j];
				b=j-b+i;
			}
			for(int j=1;j<=m;j++){
				if(q[j]==1)s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[m]<<" ";
	}
}
