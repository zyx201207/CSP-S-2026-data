#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
long long b[N],cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
	}
	int pl=n,pr=n;
	long long l2=b[n]+1,r2=b[n],p;
	for(int i=1;b[i]<=b[n]/2;i++){
		r2-=a[i-1];
		l2-=a[i];
//		cout<<l2<<' '<<r2<<endl;
		while(b[pl-1]>=l2)pl--;
		while(b[pr-1]>=r2)pr--;
//		cout<<pl<<" "<<pr<<endl;
		p=l2;
		for(int j=pl;j<=pr;j++){
			if(c[i]==c[j])continue;
			if(b[j]<=r2){
//				cout<<b[j]-p+1<<' ';
				cnt+=b[j]-p+1;
				p=b[j]+1;
			}
			else{
				cnt+=r2-p+1;
//				cout<<r2-p+1<<" ";
			}
		}
//		cout<<endl;
	}
	cout<<cnt;
	return 0;
}
