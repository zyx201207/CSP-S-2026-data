#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	long long l;
	cin >>l;
	char b[100000010]={0},a[100000010]={0};
	long long s=1;
	for(long long i=1;i<=l;i++){
		int n,m;
		cin>>n>>m;
		for(long long j=s,z=1;j<=s+n;j++,z++){
			b[j]=m;
		}
		s=s+n;
	}
	long long h=0;
	for(long long i=1,j=s/2;i<=s/2;i++,j--){
		a[i]=b[i];
		a[j]=b[i];
	}
	if(s%2!=0){
		a[s/2+1]=b[s/2+1];
	}
	for(long long i=1;i<=s;i++){
		if(b[i]!=a[i]){
			h++;
		}
	}
	cout <<h;
	return 0;
}