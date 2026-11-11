#include<bits/stdc++.h>
using namespace std;
long long n,m,f,ans;
bool p;
int a[500005],c[500005],b[300005];
/*bool find(long long f,long long x){
	int lf=1,ri=f,mid;
	while(lf<ri){
		mid=(lf+ri)/2;
		if(c[mid]==x) return 1;
		else if(c[mid]>x){
			ri=mid-1;
		}else{
			lf=mid+1;
		}
	}return -1;
}*/
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f=1;
		for(int j=1;j<=n-i+1;j++) c[i]=0;
		for(int j=i;j<=n;j++){
			p=1;
			for(int k=1;k<f;k++){
				if(c[k]==a[j] && p){
					p=0;
					f=k;
				}
				if(p==0) c[k]=0;
			}
			c[f]=a[j];
			f++;
		}
		for(int j=1;j<f;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
