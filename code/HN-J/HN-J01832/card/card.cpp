#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;
long long n,m,l=1,ll;
long long a[N],b[N],am[N];
bool sss=false;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		l=1;
		b[l]=a[i];
		for(long long j=i+1;j<=n;j++){
			sss=false;
			for(long long z=1;z<=l;z++){
				if(a[j]==b[z]){
					ll=z;
					sss=true;
					for(long long zq=z;zq<=l;zq++){
						b[zq]=0;
					}	
				}
			}
			if(sss==true){
				l=ll;
				b[l]=a[j];
			}else{
				l++;
				b[l]=a[j];
			}
		}
		for(long long j=1;j<=l;j++){
			am[b[j]]++;
			b[j]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<am[i]<<" ";
	}
	return 0;
}
