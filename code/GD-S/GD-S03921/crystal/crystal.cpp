#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n;
ll a[N],b[N],c[N],d[N],ch[N],x,m;
int check(int y){
	int l=1,r=y;
	while(l<r){
		int mid=(l+r)/2;
	//	cout <<y<<" "<<mid<<endl;
	//	cout <<c[y]*(y-mid)-(d[y]-d[mid-1])<<endl;
		if(c[y]*(y-mid)-(d[y]-d[mid-1])>m)l=mid+1;
		if(c[y]*(y-mid)-(d[y]-d[mid-1])<=m)r=mid;
	}
	return l;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >>n>>m;
	for(int i=1;i<=n;i++)cin >>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1],c[i]=c[i-1]+b[i],d[i]=c[i-1]+d[i-1];
	for(int i=1;i<=n;i++)ch[i]=check(i);
	/*
	for(int i=1;i<=n;i++)cout <<a[i]<<" ";
	cout <<endl;
	
	cout <<endl;
	for(int i=1;i<=n;i++)cout <<b[i]<<" ";
	cout <<endl;
	
	cout <<endl;
	for(int i=1;i<=n;i++)cout <<c[i]<<" ";
	cout <<endl; 
	cout <<endl;
	for(int i=1;i<=n;i++)cout <<d[i]<<" ";
	cout <<endl; 
	cout <<endl;
	for(int i=1;i<=n;i++)cout <<ch[i]<<" ";
	cout <<endl; 
	*/
	int z=1,sum=1,ma=0,y;
	for(int i=2;i<=n;i++){
		if(a[z]!=a[i]){
			//cout <<z<<" "<<i<<endl;
			if(i-1-ch[i-1]>y-ch[y])ma=sum,y=i-1;
			sum=1;
		//	cout <<y<<endl;
			z=i;
		}else sum++;
	}
	if(n-ch[n]>y-ch[y])cout <<n-ch[n]+1;
	else cout <<y-ch[y]+1;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
