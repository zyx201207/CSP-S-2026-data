#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int temp[300010];
int res[300010];
int pos,cnt;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		cnt++;
		if(a[i]!=a[i-1]){
			cout<<cnt<<' ';
			//cnt=0;
		}
	}
	
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//int n,m;
//int a[500010];
//int temp[300010];
//int res[300010];
//int pos;
//signed main(){
////	freopen("card.in","r",stdin);
////	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=m;i++){
//		//binary_scarch();
//		//int res=0;
//		memset(temp,0,sizeof(temp));
//		for(int j=i;j<=n;j++){
//			if(temp[a[j]]==0){temp[a[j]]=j;}//pos++;}
//			else{
//				pos=temp[a[j]];
//				for(int x=1;x<=m;x++)if(temp[x]>=pos)temp[x]=0;
//			}
//		}
//		for(int x=1;x<=m;x++)if(temp[x]<=pos)res[x]++;
//	}
//	for(int i=1;i<=m;i++)cout<<res[i]<<' ';
//	return 0;
//}
