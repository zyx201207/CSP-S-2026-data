#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q=0;i
		nt a[500001],b[500001];
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(a[k]==a[j]){
					for(int s=k;s<=j;s++){
						b[s]=1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]==0&&a[j]==i){
				q++;
			}
		}
		cout<<q;
	}
	return 0;
}
