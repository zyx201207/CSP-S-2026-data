#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
string c[200005];
int n,m;
string z;
/*
string aaa(int x){
	long long s=1,i=1,ccc=0;
	while(s<=x){
		s*=2;
	}
	s/=2;
	ccc+=s;
	z[i]='1';
	while(s>1){
		i++;
		if(ccc+s/2<=x){
			ccc+=s/2;
			z[i]='1';
		}
		else{
			z[i]='0';
		}
		s/=2;
	}
}
void abc(int z){
	if(z<m){
		for(int i=z;i<=n;i++){
			b[z]=a[i];
		}
		return abc(z+1);
	}
	else{
		for(int i=1;i<=m;i++){
			c[i]=aaa(b[i]);
		}
	}
}
*/
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//abc(1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(a[j]>=a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	cout<<a[n];
	//cout<<cnt;
	return 0;
}
