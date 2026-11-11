#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
char p;

long long cnt;
struct kashiko{
	long long a;
	char b;
	//a:cishu
	//b:fuhao
};
kashiko a[200005];
kashiko b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		b[n-i+1].a=a[i].a;
		b[n-i+1].b=a[i].b;
		m+=a[i].a;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i].a<<" "<<a[i].b<<" "<<b[i].a<<" "<<b[i].b<<endl;
//	}
	long long ifora,jfora,iforb,jforb;
	ifora=jfora=1;
	iforb=jforb=0;
	//a:zushu
	//b:dijige
	for(long long i=1;i<=((m+1)/2);i++){
		iforb++;
		jforb++;
		if(iforb>a[ifora].a){
			iforb=1;
			ifora++;
		}
		if(jforb>b[jfora].a){
			jforb=1;
			jfora++;
		}
		if(a[ifora].b!=b[jfora].b){
			ans++;
		//	cout<<i<<":"<<ifora<<" "<<jfora<<" "<<iforb<<" "<<jforb<<endl;
		}
//			cout<<i<<":"<<ifora<<" "<<iforb<<" "<<jfora<<" "<<jforb<<" "<<ans<<" "<<a[ifora].b<<" "<<b[jfora].b<<endl;
	}
	cout<<ans;
}
