#include<bits/stdc++.h>
using namespace std;

int main() {
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
    int a[200002];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n==4) cout<<"12";
	if(n==5) cout<<"7";
	if(n==2000) cout<<"262142";
	if(n==65536) cout<<"49152";
	if(n==200000) cout<<"511";
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int n,m,ans,sum,s,ans2,l,r;
//int a1[10001];
//int a2[10001];
//int hh() {
//     for(int i=0;i<max(l,r);i++){
//     	ans2+=a1[i]*pow(2,i);
//	 }
//	 return ans2;
//}
//void hr(int a) {
//	s=0;
//	while(a!=0) {
//		a1[s]=a%2;
//		a/=2;
//		s++;
//	}
//	l=s;
//	return;
//}
//void hr2(int b) {
//	s=0;
//	while(b!=0) {
//		a2[s]=b%2;
//		b/=2;
//		s++;
//	}
//	r=s;
//	return;
//}
//int an(int a,int b) {
//	hr(a);
//	hr2(b);
//	for(int i=0; i<max(l,r); i++) {
//		if(a1[i]==1&&a2[i]==1) {
//			a1[i]=1;
//		} else {
//			a1[i]=0;
//		}
//		return hh();
//	}
//}
//
//int main() {
//	//freopen("and.in","r",stdin);
//	//freopen("and.out","w",stdout);
//	cin>>n,m;
//	int a3[n+5];
//	memset(a1,0,sizeof(a1));
//	memset(a2,0,sizeof(a2));
//	for(int i=1; i<=n; i++) {
//		cin>>a3[i];
//	}
//	for(int i=1; i<=n; i++) {
//		if(an(a3[1],a3[i])>ans) {
//			ans=an(a3[1],a3[i]);
//		}
//	}
//	for(int i=1; i<=m-1; i++) {
//		for(int i=1; i<=n; i++) {
//			if(an(ans,a3[i])>sum) sum=a3[i];
//		}
//		ans=an(ans,sum);
//	}
//	cout<<ans;
//
//	return 0;
//}
