#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		int n,m,sum=0,num=0;
		const int N=1e+5;
		 int  b[N];
		 int  a[N];
		 int  c[N];
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
			c[i]=a[i];
			int pj;
			 pj+=a[i];
				pj/=n;
				b[i]-=pj;
			}
			int min=999999999;
			int flag=0;
			for(int i=0;i<n;i++){
			if(b[i]<min){
				min=b[i];
				flag=i;
			}
		}
			int d=0;
			for(int i=0;i<n;i++){
				c[i]=abs(a[i]-a[flag]);
				sort(c,c+n-1);
			}
				for(int i=0;i<n;i++){
				if(sum<=m){
					sum+=c[d];
					if(sum<=m){
					d++;
					num++;
				}else{
					cout<<num;
					return 0;
				}
				}
		}
		cout<<num;
	return 0;
} 
