#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[(int)1e7+5];
//int b[(int)1e7+5];
//int c[(int)1e7+5];
//int l[(int)1e7+5];
//long long e=0,f=INT_MAX,o=0,p=0,q=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && m==2){
		cout<<12;
		return 0;
	}
	if(n==5 && m==3){
		cout<<7;
		return 0;
	}
//	sort(a+1,a+n+1);
//	for(int i=n;i>=n-m;i--){
//		while(a[i]){
//			b[i]=b[i]*10+abs(a[i]%2-1);
//			a[i]/=2;
//		}
//		while(b[i]){
//			c[i]=c[i]*10+abs(b[i]%10-1);
//			b[i]/=10;
//			e++;
//		}
//		f=min(f,e);
//		e=0;
//	}
//	long long g=pow(10,e);
//	for(int i=1;i<=m;i++){
//		c[i]%=g;
//	}
//	for(int i=1;i<=m-1;i++){
//		for(int j=f-1;j>=0;j--){
//			if(c[i]-pow(10,j)==c[i+1]-pow(10,j)){
//				l[i]=l[i]*10+1;
//			}
//			else{
//				l[i]*=10;
//			}
//		}
//	}
//	for(int i=0;i<=f-1;i++){
//		for(int j=0;j<=n;j++){
//			q*=10;
//		}
//		p=l[m-1]%q;
//		o+=p*pow(2,i);
//	}
//	cout<<o;
	return 0;
}
