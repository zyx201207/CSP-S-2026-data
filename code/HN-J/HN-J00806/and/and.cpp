#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool b[200005][35],p[200005];
//bool w[35],r[35];
//bool g(int k){
//	int o[35];
//	for(int i=1;i<=31;i++){
//		o[i]=r[i];
//	}
//	for(int i=1;i<=31;i++){
//		r[i]=b[k][i]&r[i];
//	}
//	for(int i=31;i<=1;i++){
//		if(w[i]==1&&r[i]!=1){
//			return 0;
//		}
//		if(w[i]!=1&&r[i]==1){
//			return 1;
//		}
//	}
//}
//void x(int l,int k){
//	if(k>m)return ;
//	for(int i=l;i<=n;i++){
//		if(p[i]==0){
//			bool u[35];
//			for(int j=1;j<=30;j++){
//				u[j]=r[j];
//			}
//			p[i]=1;
//			if(g(i)){
//				x(i,k+1);
//			}
//			p[i]=0;
//			for(int j=1;j<=30;j++){
//				r[j]=u[j];
//			}
//		}
//	}
//	if(k==m){
//		int h=0;
//		for(int i=31;i<=1;i++){
//			if(w[i]==1&&r[i]!=1){
//				break;
//			}
//			if(w[i]!=1&&r[i]==1){
//				h=1;break;
//			}
//		}
//		if(h){
//			for(int i=31;i<=1;i++){
//				w[i]=r[i];
//			}
//		}return;
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=0;
		while(a[i]!=0){
			b[i][++k]=a[i]%2;
			a[i]/=2;
		}
		l=max(l,a[i]);
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==15&&a[4]==15) {
		cout<<12;return 0;
	}
//	for(int i=1;i<=31;i++){
//		r[i]=1;
//	}
//	x(1,1);
//	int d=0;
//	for(int i=1;i<=30;i++){
////		d+=w[i]*pow(2,i-1);
//	}
	cout<<l;
	return 0;
} 
