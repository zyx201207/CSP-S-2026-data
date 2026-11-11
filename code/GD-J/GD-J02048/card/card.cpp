#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int f[N],s[N];
int num[N];
int sum[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=s[a[i]];
		s[a[i]]=i;
	} 
//	for(int i=1;i<=m;i++){
//		maxn=max(maxn,s[a[i]]);
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			num[j]=0;
//		}
//		for(int j=i;j<=n;j++){
//			if(num[a[j]]){
//				for(int k=num[a[j]];k<=j-1;k++){
//					num[a[k]]==0;
//				} 
//			}
//			num[a[j]]=j;
//		}
//		for(int j=1;j<=m;j++){
//			if(num[j]>=1){
//				sum[j]++;
//			}
//		} 
//	} 
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
