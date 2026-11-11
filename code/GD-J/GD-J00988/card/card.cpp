#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#define ll long long
using namespace std;

const int maxn = 5000+10;
int a[maxn],p[maxn],cnt[maxn];
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof p);
		for(int j=i;j<=n;j++){
			if(p[a[j]]!=0){
				for(int k=p[a[j]];k<j;k++) p[a[k]]=0;
			}
			p[a[j]]=j;
		}
		for(int j=1;j<=m;j++) if(p[j]!=0) cnt[j]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}

