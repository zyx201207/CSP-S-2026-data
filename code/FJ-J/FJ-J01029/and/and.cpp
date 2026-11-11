#include <bits/stdc++.h>
using namespace std;
int a[1000005],diff[100005];
string f[1000005];
string to2(int x){
	int cnt=0;
	string b,s;
	int i=0;
	while(x){
		i++;
		b[i]=x%2;
		x=x/2;
	}
	for(int j=1;j<=i;j++){
		s[i]=b[j];
		i--;
	}
	return s;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	cin >>n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=to2(a[i]);
	}
	int k=0;
	for(int i=1;i<=n;i++){
		while(f[i]){
			k++;
			if(f[i]%10==1)
				diff[t]++;
			f[i]=f[i]/10;
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		if(diff[i]>=m)	sum+=diff[i]*sqrt(10,i);
	}
	cout <<sum;
	
	return 0;
}