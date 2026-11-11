#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],zh[500005],t1[500005],top,f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
	}
	if(n<=30505){
		for(int i=0;i<n;i++){
			int t[50505]={};
			for(int j=n-1;j>=1;j--){
				if(t[a[j]]==0){
					t[a[j]]=1;
					zh[++top]=a[j];
				}else{
					while(zh[top]!=a[j]){
						top--;
					}
				}
			}
			for(int j=1;j<=top;j++){
				t1[zh[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t1[i]<<" ";
		}
	}else if(f==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				t1[j]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t1[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
