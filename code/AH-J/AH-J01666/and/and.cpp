#include<bits/stdc++.h>
using namespace std;
const int N=2000100;
int a[N],d[N],n,m,ans;
int p(int x,int y){
	int s1=0,s2=0;
	while(x||y){
		if(x%2){
			x-1;
			s1++;
		}
		if(y%2){
			y-1;
			s2++;
		}
		x/=2;y/=2;
	}
	return s1>s2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=m;j>0;j--){
			if(j>1)d[j]=max(d[j],(d[j-1]&a[i]));
			if(j==1){
				if(p(a[i],d[j]))d[j]=a[i];
			}
		}
	}
	cout<<d[m];
	return 0;
}
