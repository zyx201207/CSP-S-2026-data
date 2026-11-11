#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
} 
struct node{int x;char ch;}a[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read(),m=0;
	for(int i=1;i<=n;i++){
		a[i].x=read();
		m+=a[i].x;
		cin>>a[i].ch;
	}
	int r=n,l=1,ans=0;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			if(a[l].x>=a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}else{
			if(a[l].x>=a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else{
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
