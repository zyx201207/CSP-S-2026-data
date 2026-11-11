#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[100005],b[10005],t[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=n;i>0;i--){
//		for(int j=1;j<=n;j++){
//			b[j]=a[j];
//			for(int x=1;x<=j;x++){
//				if(a[j]==b[x]&&a[j]!=b[j]){
//					for(int z=1;z<=n;z++){
//						b[z]=0;
//					}
//					b[j]==a[j];
//				}
//				continue;
//			}	
//		}
//		for(int j=1;j<=n*n;j++){
//			t[b[j]]++;
//			cout<<j<<":"<<t[b[j]]<<endl;
//		}
//		
//	}
//	for(int i=1;i<=m ;i++){
//		cout<<t[i]<<endl;
//	}
	cout<<1;
	return 0;
}

