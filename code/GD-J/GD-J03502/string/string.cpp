#include<bits/stdc++.h>
using namespace std;
struct s{
	int m;
	char b;
};
s z[200005];
char a;
long long int n,l,zl,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>a;
		z[i].m=l;
		z[i].b=a;
		zl+=l;
	}
	zl/=2;
	l=0;
	int r=n-1;
	while(zl){
		if(z[l].b!=z[r].b){
			zl=zl-min(z[l].m,z[r].m);
			sum=sum+min(z[l].m,z[r].m);
			if(z[l].m>z[r].m)l++;
			else if(z[l].m==z[r].m){
				l++;
				r--;
			}else r--;
			
		}else{
			zl=zl-min(z[l].m,z[r].m);
			if(z[l].m>z[r].m)l++;
			else if(z[l].m==z[r].m){
				l++;
				r--;
			}else r--;
		}
	}
	cout<<sum;
	return 0;
}
