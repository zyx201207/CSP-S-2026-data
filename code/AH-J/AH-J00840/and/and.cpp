#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[50],c[50],d[50],maxn=0,a1;
long long x,y;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q+m-1<=n;q++){
		for(int i=q;i<=q+m-1;i++){
			int a2=a[i+1],a4=a[i+1],a3=0,k1=0,k2=0,k=0,k3=0,num=1;
			for(int j=0;j<=50;j++){
				b[j]=0;
				c[j]=0;
			}
			if(i==q){
				a1=a[i];
			}
			int a5=a1;
			while(a5!=0){
				a5=a5/2;
				k1++;
			}
			while(a4!=0){
				a4=a4/2;
				k2++;
			}
			
			
			k=max(k1,k2);
			while(k1!=0){
				b[k-k1+1]=a1%2;
				a1=a1/2;
				k1--;
			}
			while(k2!=0){
				c[k-k2+1]=a2%2;
				a2=a2/2;
				k2--;
			}
			for(int j=k;j>=0;j--){
				if(b[j]==c[j]&&b[j]==1){
					a3=a3+num;
				}
				num=num*2;
			}
			a1=a3;
		}
		maxn=max(a1,maxn);
	}
	cout<<maxn;
	return 0;
}
