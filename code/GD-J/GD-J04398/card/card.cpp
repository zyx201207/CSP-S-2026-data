#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300010],b[300010],c[300010],q[300010];
int main(){
	freopen("card.in" , "r" , stdin );
	freopen("card.out" , "w" , stdout );
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(q,0,sizeof(q));
		long long ql=0;
		for(int l=i;l<=n;l++){
			long long x=a[l];
			if(b[x]!=0){
				while(ql && q[ql]!=x){
					b[q[ql]]=0;
					ql--;
				}
			}else{
				ql++;
				b[x]=1;
				q[ql]=x;
			}
		}
		while(ql){
			c[q[ql]]++;
			ql--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
