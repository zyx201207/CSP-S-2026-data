#include <bits/stdc++.h> 
using namespace std;
int n,a[200010];
long long x,y;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	int f=0,f2=0,f3=0,f4=1;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		cin >>b[i];
		x+=a[i];
	}
	if (x%2==0) x/=2;
	else{
		x=x/2+1;
		f4=0;
	}
	for (int i=1;i<=n;i++){
		x-=a[i];
		if (x<=0){
			f=i;
			f2=abs(x);
			f3=a[i]-f2;
			break;
		}
	} 
	long long u=0,u2=0;
	char u3,u4;
	for (int i=1;i<=f-1+f4;i++){
		if (u==0){
			u=a[i];
			u3=b[i];
		}
		if (u2==0){
			u2=a[n-i+1];
			u4=b[n-i+1];
		}
		if(u>=u2){
			if (u3!=u4){
				y+=u2;
				u-=u2;
				u2=0;
			}
		}
		else{
			if (u3!=u4){
				y+=u;
				u2-=u;
				u=0;
			}
		}
	}
	if (f2!=0){
		if (u+f2==f3){
			if (u3!=b[f]){
				y+=u2;
			}
		}
		else{
			if (u4!=b[f]){
				y+=u;
			}
		}
	}
	cout <<y;
	return 0;
}
