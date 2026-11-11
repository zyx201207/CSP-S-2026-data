#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum=0,e=-1;
char c[200010];
char v[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			v[++e]=c[i];
		}
	}
	long long l,r;
	l=0;
	r=e;
	long long i=0;
	while(l<=r){
		if(v[l]!=v[r]) i++;
		l++;
		r--; 
	}
	cout<<i;
	return 0;
}
