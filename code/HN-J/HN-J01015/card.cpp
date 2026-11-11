#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500010],b[500010],c[300010],l=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i1=1;i1<=n;i1++){
		int d[500010]={0};
		for(int i2=i1;i2<=n;i2++){
			if(d[a[i2]]){
				l=d[a[i2]]+1;
				for(int i3=l;i3<i2;i3++){
					d[a[i3]]=0;
				}
			}else{
				b[l]=a[i2];
				d[a[i2]]=i2;
				l++;
			}
		}
		for(int i2=1;i2<l;i2++){
			c[b[i2]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
//	 		
