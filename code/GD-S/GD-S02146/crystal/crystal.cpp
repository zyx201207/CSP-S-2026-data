#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],b[500005],res;
/*
long long f(int x){
	long long res=0;
	for(int i=0;i<=x;i++){
		res+=a[x]-a[i];
	}
	return res;
} 
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	/*
	long long l=0,r=n,mid=0;
	while(l<r){
		mid=(r-l)/2;
		long long res=f(mid);
		//if(res==m){
		//	ans=mid;
		//	cout<<mid<<endl;
		//	break;
		//}
		if(res<=m) l=mid+1;
		else if(res>m) r=mid-1;
	}
	*/
	for(int i=0;i<n;i++){
		res=0;
		for(int j=0;j<=i;j++){
			res+=a[i]-a[j];
		}
		b[i]=res;
	}
	for(int i=0;i<n;i++){
		if(b[i]>m){
			break;
		}
		ans=i;
	}
	//for(int i=0;i<n;i++) cout<<b[i]<<" ";
	printf("%lld",ans+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

