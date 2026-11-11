#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
long long m;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int k=ceil(n*1.0/2);
//	cout<<k<<endl;
	for(int i=1;i<=k;i++){
//		cout<<i<<' '<<n-i+1<<' '<<c[i]<<' '<<c[n-i+1]<<' '<<a[i]<<' '<<a[n-i+1]<<' ';
		if(i>n/2) break;
		if(c[i]!=c[n-i+1]){
			if(a[i]<a[n-i+1]){
				m+=a[i];
				a[n-i+1]=a[n-i+1]-a[i];
				n++;
			}else if(a[i]>a[n-i+1]){
				m+=a[n-i+1];
				a[i]=a[i]-a[n-i+1];
				n--;
				i--;
			}else if(a[i]==a[n-i+1]){
				m+=a[i];
			}
		}else{
			if(a[i]<a[n-i+1]){
				a[n-i+1]=a[n-i+1]-a[i];
				n++;
			}else if(a[i]>a[n-i+1]){
				a[i]=a[i]-a[n-i+1];
				n--;
				i--;
			}
		}
//		cout<<m<<endl; 
	}
	cout<<m;
	return 0;
}
