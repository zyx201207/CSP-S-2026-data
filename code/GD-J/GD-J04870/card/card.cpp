#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005];
bool v[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(v,0,m+1);
		for(int i=k;i<=n;i++){
			if(v[a[i]]==1){
				for(int j=a[i]+1;j<=m;j++){
					v[j]=0;
				}
			}else v[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(v[i])t[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
