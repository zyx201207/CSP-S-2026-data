//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N=5e5+5,M=3e5+6;
//int t[N],a[N],n,m,sum[M],f[M],ans[N];
//int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;++i){
//		cin>>a[i];
//	}
//	for(int i=n;i>0;--i){
//		if(t[a[i]]==0)t[a[i]]=i;
//		sum[a[i]]++;
//	}
//	for(int i=1;i<=n;++i){
//		ans[a[i]]++;
//		if(f[a[i]])continue;
//		int k=1;
//		for(int j=t[a[i]]+1;j<=n;++j){
//			if(f[a[j-1]]==0)ans[a[j]]+=sum[a[j-1]];
//			else{ans[a[j]]+=k;
//				k=k*sum[a[j-1]];
//				
//			}
//			f[a[j-1]]=1;
//			j=t[a[j]];
//		}
////		cout<<i<<" "<<ans[3]<<"\n";
//	}
//	for(int i=1;i<=m;++i){
//		cout<<ans[i]<<" ";
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+6;
int t[N],a[N],n,m,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>0;--i){
		if(t[a[i]]==0)t[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		ans[a[i]]++;
		for(int j=t[a[i]]+1;j<=n;++j){
			ans[a[j]]++;
			j=t[a[j]];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
