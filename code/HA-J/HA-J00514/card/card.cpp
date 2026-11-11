#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[555555];
int s[333333];
int b[555555];
int len=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		len=0;
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			bool f=0;
			for(int k=1;k<=len;k++){
				if(b[k]==a[j]){
					f=1;
					len=k;
					break;
				}
			}
			if(f==0)b[++len]=a[j];
		}
		for(int j=1;j<=len;j++){
			s[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
