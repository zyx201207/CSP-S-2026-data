#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int t[m+1]={0},l[m+1]={0};
	bool r[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		t[a[i]]+=i;
		
		if(l[a[i]]==1){
			for(int j=i;j==i||a[j]!=a[i];j++){
				if(t[a[j]]-i>0&&r[j]==0)t[a[j]]-=i;
				r[j]=1;
			}
		}
		l[a[i]]=1;
		
	}
	for(int k=1;k<=m;k++)cout<<t[k]<<" ";
		cout<<endl;
	return 0;
} 
