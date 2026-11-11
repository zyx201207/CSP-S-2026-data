#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+10;
int a[N],kind;
bool cmp(int c1,int c2){return ((c1>>kind)&1)>((c2>>kind)&1);}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=30;i>=0;i--){
		kind=i,sort(a+1,a+n+1,cmp);
		int k=0;
		for(int j=1;j<=n;j++)
			if((a[j]>>i)&1) k++;
		if(k>=m) n=k,ans=ans*2+1;
		else ans*=2;
	}
	printf("%d",ans);
	return 0;
}
