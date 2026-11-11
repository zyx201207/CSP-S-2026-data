#include<bits/stdc++.h>
using namespace std;
long long sl,ch,z,dn=0,a[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort (a+1,a+1+n);
	ch=a[1];
	sl=1;
	z=a[1];
	int flag=1;
	for(long long i=2;i<=n;i++){
		if(flag){
			ch=a[i]-a[i-1];
		}else{
			ch=a[i]-z;
		}
		if(m-sl*ch>=0){
			m-=sl*ch;
			sl++;
			z=a[i];
			flag=0;
		}
	}
	cout <<sl;
	return 0;
} 
