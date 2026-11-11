#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],b[200001],x=0,d,z=0;
void huan(int h){
	b[h]+=1;
	if(b[h]>d+h){
		if(h==1){
			z=1;
			return;
		}
		huan(h-1);
		b[h]=b[h-1]+1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	d=n-m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) b[i]=i;
	while(1){
		long long c=a[b[1]];
		for(int i=2;i<=m;i++){			
			c=c&a[b[i]];			
		}
		x=max(x,c);
		huan(m);
		if(z==1) break;
	}
	cout<<x;
	
	return 0;
} 
