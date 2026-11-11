#include<bits/stdc++.h>
using namespace std;

long long n,m,b[100010],c,d=-1,e=1000000,g,h;
char a[10010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>b[i];
	if(b[i]>d){
		c=b[i];
	}
	if(b[i]<e){
		e=b[i];
	}
	
}
for(int i=1;i<=n;i++){
	g=c-e;
	if(b[i]-g<b[i-1]-g){
		h=b[i];
	}
}
cout<<h;
	return 0;
}
