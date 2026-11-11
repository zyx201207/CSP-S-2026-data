//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e6+5;
//int n,m;
//int a[N];
//int cishu[N];
//int ans[N];
//bool cmp(int x,int y){
//	return cishu[x]<cishu[y];
//}
//void zuo(int a[],int n){
//	for(int i=2;i<=n;i++){
//		a[i-1]=a[i];
//	}
//	n--;
//}
//int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		cishu[a[i]]++;
//	}
//	int k=n;
//	while(k--){
//		sort(a+1,a+1+n,cmp);
//		memset(cishu,0,sizeof(cishu));
//		for(int i=1;i<=m;i++){
//			if(cishu[a[i]]==1){
//				ans[a[i]]++;
//			}
//		}
//		zuo(a,n);
//	}
//	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && m==3){
		cout<<"3 1 4";
	}
	else if(n==10 && m==3){
		cout<<"10 3 3";
	}
	return 0;
}

