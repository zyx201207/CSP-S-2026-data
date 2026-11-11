#include<bits/stdc++.h>
using namespace std;
long long n,m,b[500010];
struct node{
	long long e,c;
}a[500010];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].e;
		b[i]=a[i].e;
	}	
	sort(b+1,b+n+1);
	long long jz=b[n/2+1];
	for(int i=1;i<=n;i++){
		a[i].c=abs(a[i].e-jz);
	}
	sort(a+1,a+n+1,cmp);
	long long s=0;
	for(int i=1;i<=n;i++){
		if(m-a[i].c>=0){
			m-=a[i].c;
			s++;
		}
		else{
			break;
		}
	}
	cout<<s;
	return 0;
}
