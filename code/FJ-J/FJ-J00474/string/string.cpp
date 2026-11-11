#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+7;

struct node{
	int x;
	char c;
}a[maxn];
bool vis[maxn];
int pre[maxn];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int j=n+1,cnt=0,suml=0,sumr=0;
	char r,l;
	bool ok=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(!suml && !sumr)break;
		}
		else {
			l=a[i].c;
			suml+=a[i].x;
			vis[i]=1;
		}
		while(suml && j>=i){
			if(!sumr){
				j--;
				if(!vis[j]){
					vis[j]=1;
					sumr+=a[j].x;
					r=a[j].c;
				}
			}
			if(r==l){
				if(suml > sumr){
					suml-=sumr;
					sumr=0;
					continue;
				}
				else {
					sumr=sumr-suml;
					suml=0;
					break;
				}
			}
			else {
				if(suml > sumr){
					cnt+=sumr;
					suml-=sumr;
					sumr=0;
					continue;
				}
				else {
					cnt+=suml;
					sumr=sumr-suml;
					suml=0;
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
