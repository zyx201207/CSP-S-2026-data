#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXX=2e5+5;
int n,m,sum;
int maxx=0;
struct node{
	int a;
}p[MAXX];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>p[i].a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				sum=p[i].a&p[j].a;
			}
			if(sum>maxx) maxx=sum; 
		}
	}
	cout<<maxx;
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int MAXX=2e5+5;
//int n,m,sum=0,cnt=1;
//int maxx;
//struct node{
//	int a;
//}p[MAXX];
//int dfs(int a){
//	if(a>=m) return maxx;
//	sum=p[cnt].a;
//	for(int i=1;i<m&&cnt<n-m;i++) sum=sum&p[i+1].a;
//	if(sum>maxx) maxx=sum;
//	cnt++;
//	dfs(a+1);
//}
//signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++) cin>>p[i].a;
//	dfs(m,-1);
//	cout<<maxx;
//	return 0;
//}
