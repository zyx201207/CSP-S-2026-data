#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
//int check(int x,int zzz){
//	for(int i=1;i<=zzz;i++){
//		if(b[i]==x){
//			return i;
//		}
//	}
//	return 0;
//}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	b[a[n]]=n;
	for(int i=1;i<n;i++){
		if(a[i]==a[n]){
			continue;
		}
		b[a[i]]++;
	}
	for(int i=1;i<=ma;i++){
		cout<<b[i]<<' '
	}
//	for(int i=1;i<=n;i++){
//		int zzz=0;
//		for(int j=i;j<=n;j++){
//			int jj=check(a[j],zzz);
//			if(jj){
//				for(int z=jj;z<=zzz;jj++){
//					b[z]=0;
//					zzz--;
//				}
//			}
//			b[j]=a[j];
//			zzz++;
//		}
//		for(int j=1;j<=zzz;j++){
//			cout<<b[i]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
}


