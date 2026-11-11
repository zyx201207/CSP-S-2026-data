#include<bits/stdc++.h>
using namespace std;
long long n,sum;
string f[10000005],b[1000005];
struct node{
	int k;
	string s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].s;
		for(int j=t;j<t+a[i].k;j++){
			f[j]=a[i].s;
		}
		t+=a[i].k;
	}
	int ans=0;
	for(int i=t-1;i>=0;i--){
		b[i]=f[ans];
		ans++;
	}
	for(int i=0;i<(t+1)/2;i++){
		if(f[i]!=b[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
