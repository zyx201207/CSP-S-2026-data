#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
long long int n,m,a[N],b[N],s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	int sum=b[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		sum+=b[i];
		s++;
		if(sum>m){
			break;
		}
	}
	cout<<s;
	return 0;
}
