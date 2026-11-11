#include<bits/stdc++.h>
using namespace std;
long long a[200005]={0},n,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	string c,sc="0";
	cin>>n;
	a[1]=1;
	for(long long i=1;i<=n;i++){
//		cin>>a[i];
//		cin>>c;
		scanf("%lld",&a[i+1]);
		a[i+1]+=a[i];
		cin>>c;
		sc=sc+c;
	}
	for(long long i=1;i<=n && a[i]*2<a[n+1];i++){
		long long fie=a[n+1]-1-a[i]+1,fis=a[n+1]-1-a[i+1]+1+1;
		long long xs=lower_bound(a+1,a+n+1,fis)-a;
		long long xe=lower_bound(a+1,a+n+1,fie)-a;
		
		if(a[xs]>fis){
			xs--;
		}
		for(long long j=xs;j<=xe && j<=n;j++){
			
			if(sc[j]!=sc[i]){
//				cout<<i<<' '<<xs<<' '<<xe<<' '<<fie<<' '<<fis<<' '<<a[i+1]<<' ';
				sum=sum+min(fie,a[j+1]-1)-max(fis,a[j])+1;
//				cout<<j<<' '<<min(fie,a[j+1]-1)-max(fis,a[j])+1<<' ';
			}
		} 
	}
	cout<<sum;
//	int a[10]={1,3,5,6,8,8};
//	cout<<lower_bound(a,a+5,2)-a;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
