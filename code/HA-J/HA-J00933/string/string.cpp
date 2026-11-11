#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],zx,yx,bx,j=1,tot=1;
long long cnt,sum,ans;
char c[N];
struct node{
	long long l,r;
	char s;
}z[N],y[N],b[N<<1],d[N<<1];
int main(){
	//关注luogu 1406766 谢谢喵
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	memset(z,0,sizeof(z));
	memset(y,0,sizeof(y));
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt=cnt+1ll*a[i];
	}
	for(;j<=n;j++){
		sum+=a[j];
		if(sum>=cnt/2){
			z[++zx].l=sum-a[j]+1;
			z[zx].r=cnt/2;
			z[zx].s=c[j];
			break;
		}
		z[++zx].l=sum-a[j]+1;
		z[zx].r=sum;
		z[zx].s=c[j];
	}
	y[++yx].l=z[zx].r+1;
	y[yx].r=sum;
	y[yx].s=c[j];
	j++;
	if(y[yx].l>y[yx].r) yx--;
	for(;j<=n;j++){
		sum+=a[j];
		y[++yx].l=sum-a[j]+1;
		y[yx].r=sum;
		y[yx].s=c[j];
	}
	if(cnt%2)for(int i=1;i<=yx;i++)if(y[i].l==cnt/2+1)y[i].l++;
	for(int i=1;i<=yx/2;i++)swap(y[i],y[yx-i+1]);
	for(int i=1;i<=yx;i++){
		node t=y[i];
		y[i].l=cnt-t.r+1;
		y[i].r=cnt-t.l+1;
	}
//	for(int i=1;i<=zx;i++)cout<<z[i].l<<" "<<z[i].r<<" "<<z[i].s<<"\n";
//	cout<<"\n";
//	for(int i=1;i<=yx;i++)cout<<y[i].l<<" "<<y[i].r<<" "<<y[i].s<<"\n";
//	cout<<"\n";
	for(int i=1;i<=yx;i++){
		while(tot<=zx&&z[tot].r<=y[i].r){
			bx++;
			b[bx].l=b[bx-1].r+1;
			b[bx].r=z[tot].r;
			b[bx].s=y[i].s;
			tot++;
		}
		if(b[bx].r+1<=y[i].r){
			bx++;
			b[bx].l=b[bx-1].r+1;
			b[bx].r=y[i].r;
			b[bx].s=y[i].s;
		}
	}
	//for(int i=1;i<=bx;i++)cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].s<<"\n";
	tot=1;
	for(int i=1;i<=bx;i++){
		while(z[tot].r<b[i].r&&tot<=zx)tot++;
		if(b[i].s!=z[tot].s) ans=ans+(b[i].r-b[i].l+1);
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


啥史题，T2大模拟吗，有点意思 
*/

