#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000001]={};
int s[10000001]={};
int ans[100000001]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			s[i]=a[i];
		}
		for(int i=t;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[i]==s[j]){
					for(int k=i;k<j;k++){
						s[k]=0;
					}
					i=j;
				}
			}
		}
		for(int i=t;i<=n;i++){
			ans[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
