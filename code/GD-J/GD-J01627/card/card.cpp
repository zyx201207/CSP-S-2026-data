#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s(0), ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+ch-'0';
	return s;
}
long long a[500005], c[300005], jl[300005], jsq[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n=read(), m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		long long cnt=0;
		for(int j=1;j<=m;j++){
			jl[a[j]]=1e8;
		}
		for(int j=i;j<=n;j++){
			if(cnt<jl[a[j]]){
				c[++cnt]=a[j];
				jl[a[j]]=cnt;
			} 
			else{
				cnt=jl[a[j]];
			}
		}
		for(int j=1;j<=cnt;j++){
			jsq[c[j]]++;
		}		
	}
	for(int i=1;i<=m;i++){
		cout << jsq[i] << ' ';
	}	
	return 0;
} 
