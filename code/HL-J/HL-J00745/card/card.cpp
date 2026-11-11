#include<bits/stdc++.h>;
using namespace std;
int a[200010],b[200010],ans[999999]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	ans[a[n-1]]++;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(b[i]==b[j]){
				for(int k=i;k<j;k++){
					b[k]=0;
				}
			}
		}
		for(int j=i;j<n;j++){
			ans[b[j]]++;
		}
		for(int j=0;j<n;j++){
			b[j]=a[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
	
}