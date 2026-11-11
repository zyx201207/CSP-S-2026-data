#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool k[200005];
bool b[200005];
bool c[200005];
int asd,dsa;


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int h=0;h<=200000;h++){
				k[h]=0;
				b[h]=0;
				c[h]=0;
			}
			int bb=1,cc=1,x=a[i],y=a[j],asd=0;
			while (x!=0){
				b[bb]=x%2;
				x/=2;
				bb++;
			}
			while (y!=0){
				c[cc]=y%2;
				y/=2;
				cc++;
			}
			bb=max(bb,cc);
			for (int h=1;h<bb;h++){
				if (b[h]==1 && c[h]==1){
					k[h]=1;
				}
			}
			for (int h=1;h<bb;h++){
				asd+=k[h]*pow(2,h-1);
			}
			dsa=max(asd,dsa);
		}
	}
	cout<<dsa;
	return 0;
}
