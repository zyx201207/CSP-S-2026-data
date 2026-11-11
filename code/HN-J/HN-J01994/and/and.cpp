#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int n,m,o;
o=0;
int a[200005];
cin >>n>>m;
for (int i=1;i<=n;i++){
	cin >>a[i];
}
if (m==1){
	for (int i=1;i<=n;i++){
	o=max(a[i],o);
	}
}
if (m==n){
	for (int i=1;i<=n;i++){
	o=a[i]&a[i+1];
	}
	
	
	
}
cout <<o;
return 0;
} 
