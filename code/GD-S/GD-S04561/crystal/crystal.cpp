#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,b[500010],maxx=0,c[500010],m;
bool cmp(int i,int j){
	return i > j;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<n;i++){
		b[i]=a[0]-a[i];
		c[i]=c[i-1]+a[i-1]-a[i];
	}
	long long i=0,num=0;
	for(int j=0;j<n;j++){
		num+=b[j]-c[i];
		if(num>m){
			i+=1;
			num-=(j-i+1)*(c[i]-c[i-1]);
		}
		maxx=max(maxx,(j-i+1));
	}
	cout<<maxx;
	return 0;
}
