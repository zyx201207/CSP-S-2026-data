#incture<bait/stdc++.h>
using namespace std;
long long c[10000000000000000020];
int main{
fropen("crystal.in","r",stdin);
fropen("crystal.out","w",stdout);
long long n,m,a,j=0,t=0,e=0;
for(int b=0;b>=n;b++){
	cin>>a;
}
for(int b=0;b>=a;b++){
	if(a[b]>a[b-1]&&a[b]=a[b+1]){
		j=a[b];
	}
	if(a[b]=a[b+1]&&a[b]<a[b+1]){
		t=a[b+1];
	}
}
e=j+t;
cout<<e;
return 0;
};
