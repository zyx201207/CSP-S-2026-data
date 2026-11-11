#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N],n,m,b[N],ans[N];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]++;
				v.push_back(a[j]);
				ans[a[j]]++;
			}
			else{
				while(v[v.size()-1]!=a[j]){
					b[v[v.size()-1]]--;
					ans[v[v.size()-1]]--;
					v.pop_back();
				}
			}
		}
		v.clear();
	}
	for(i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
