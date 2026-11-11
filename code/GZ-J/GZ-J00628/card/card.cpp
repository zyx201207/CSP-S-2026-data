//GZ-J00628，邱光伍，贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5*1e5+5,M=1e5+5;
ull n,m;
ull a[N],d[N];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
    }
	for(int i=1;i<=n;i++){
		ull b[M],c[M];
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1) c[a[j]]=j;
			if(b[a[j]]==2){
				for(int k=c[a[j]]+1;k<j;k++) {
				b[a[k]]=0;
				c[a[k]]=0;
			}
			b[a[j]]=1;
			c[a[j]]=j;
			}
			b[a[j]]++;
			
		}
		for(int l=i;l<=m;l++) if(b[l]) d[b[l]]++;
	}
	for(ull i=1;i<=m;i++){
		cout<<d[i];
	}
	return 0;
} 
