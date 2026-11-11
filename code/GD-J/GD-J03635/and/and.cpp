#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[20005],maa=INT_MIN,pos,posi,posj;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long an=a[i]&a[j];
			posi=i;
			posj=j;
			if(an>maa){
				maa=an;
			}
		}
	}
	a[posi]=0;
	a[posj]=0;
	for(int h=1;h<=m-1;h++){
		for(int i=1;i<=n;i++){
			long long an=maa&a[i];
			pos=i;
			if(an>maa)maa=an;
		}
		a[pos]=0;
	}
	cout<<maa;
	return 0;
}
