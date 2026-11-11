#include<bits/stdc++.h>
using namespace std;
long long a[50005];
int main(){
	freopen("in.crystal","r",stdin);
	freopen("out.crystal","w",stdout);
	long long n,m,max=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int f=1;f<=n;f++){
			int t=a[f];
			if(a[f]>a[f+1]){
				a[f]=a[f+1];
				a[f+1]=t;
			}
		}
	}
	long long p=a[n/2+n%2];
	for(int i=1;i<=n/2+1;i++){
		if(m<=0){
			break;
		}
		m=m+a[i]-p;
		a[i]=p;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			max++;
		}
	}
	cout<<max;
    return 0;
}
