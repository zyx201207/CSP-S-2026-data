#include <cstring>
#include <iostream>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n,m,pos,a[N],b[M],p[M],t[M],pref[N];

int main() {
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++) {
		
		memset(p,0,sizeof(p));
		
		int l=0;
		for (int j=i; j<=n; j++) {
			
			if (!p[a[j]]) {
				
				b[++l]=a[j];
				p[a[j]]=l;
				
			}
			
			else {
				
				int tmp=p[a[j]];
				for (int k=tmp+1; k<=l; k++) p[b[k]]=0;
				l=tmp;
				
			}
			
		}
		
		for (int j=1; j<=l; j++) t[b[j]]++;
		
	}
	
	for (int i=1; i<=m; i++) cout<<t[i]<<" ";
	cout<<endl;
	
	return 0;
}
