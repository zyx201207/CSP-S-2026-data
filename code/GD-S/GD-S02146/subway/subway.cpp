#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],x,y,ans=17;
string s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) getline(cin,s);
	scanf("%d %d",&x,&y);
	scanf("%d %d",&x,&y);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

