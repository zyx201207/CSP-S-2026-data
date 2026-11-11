#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int LN=35;
int a[N];
int b[N][LN];
int s;
bool d[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;a[i]>0;j++){
			b[i][j]=a[i]&1;
			a[i]>>=1;
		}
	}
	for(int i=30;i>=0;i--){
		int c=0;
		for(int j=0;j<n;j++){
			if(b[j][i]==1&&d[j]==0) c++;
		}
		if(c<m) continue;
		for(int j=0;j<n;j++){
			if(b[j][i]==0) d[j]=1;
		}
		s+=(1<<i);
	}
	printf("%d",s);
	return 0;
}
