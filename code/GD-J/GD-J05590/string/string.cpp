#include <iostream>
#include <cmath>
using namespace std;
long long l,a,b[200005],s=0,z=0,zz,q=1;
char c,d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	zz=l-1;
	for(int i=0;i<l;i++){
		cin>>a>>c;
		b[i]=a;
		d[i]=c;
	}
	while(z!=zz){
		if(b[z]>b[zz]){
			if(d[z]!=d[zz]) s+=b[zz];
			b[z]-=b[zz];
			zz-=1;
		}
		else if(b[z]<b[zz]){
			if(d[z]!=d[zz]) s+=b[z];
			b[zz]-=b[z];
			z+=1;
		}
		else{
			if(d[z]!=d[zz]) s+=b[zz];
			z+=1;
			zz-=1;
		}
	}
	cout<<s;
}

