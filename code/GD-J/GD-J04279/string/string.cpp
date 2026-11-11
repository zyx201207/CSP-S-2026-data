#include<iostream>
using namespace std;

int n;
int a[200010];
char b[200010];
long long s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	for(;i<j;){
		int mn=min(a[i],a[j]),mx=max(a[i],a[j]);
		if(b[i]!=b[j]){
			s+=mn;
		}
		a[i]-=mn;
		a[j]-=mn;
		if(a[i]==0)++i;
		if(a[j]==0)--j;
	} 
	cout<<s;
	return 0;
} 
/*
3
2 a
2 b
1 c
2
2 a
3 a
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
