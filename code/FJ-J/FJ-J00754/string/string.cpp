#include<bits/stdc++.h>
using namespace std;
int n,l,a,w,x,y,z;
long long ai[200010];
string ci[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	y=n-1;
	for(int i=0;i<n;i++){
		cin>>ai[i]>>ci[i];
		l+=ai[i]; 
	}
	for(int i=0;i<l/2;i++){
		if(ci[w]!=ci[y]) a++;
		x++;
		if(x>ai[w]){
			x=0;
			w++;
		}
		z++;
		if(z>ai[y]){
			z=0;
			y--;
		}
	}
	cout<<a;
	return 0;
}
