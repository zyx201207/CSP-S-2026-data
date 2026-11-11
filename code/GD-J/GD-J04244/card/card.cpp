#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,k;
	cin>>n>>m;
	long long a[n+3],b[n+3]={0},c[n+3];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					for(int q=i;q<j;q++){
						a[q]=0;
					}
				}
			}
		}
		for(int i=p;i<=n;i++){
			if(a[i]!=0){
				b[a[i]]++;
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=c[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
