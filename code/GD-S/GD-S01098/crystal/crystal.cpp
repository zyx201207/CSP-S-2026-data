#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		a[i]=abs(a[i]-a[n/2]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(m>0){
			m-=a[i];
			s++;
		}
		else{
			break;
		}
	}
	cout<<s;

	return 0;
}
