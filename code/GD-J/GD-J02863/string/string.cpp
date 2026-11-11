#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int id=n;
	long long sum=0;
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else l++,r--;
		
	}
	cout<<sum;
	return 0;
}
