#include<bits/stdc++.h>
using namespace std;
const int MAXN=200009;
int n;
long long ans;
int a[MAXN];
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	
	int x=1,y=n,f=0;
	while(x<y){
		f=min(a[x],a[y]);
		if(c[x]!=c[y]){
			ans+=f;
		}
		a[x]-=f;
		a[y]-=f;
		if(a[x]==0)x++;
		else y--;
	}
	cout<<ans;
	return 0;
}
