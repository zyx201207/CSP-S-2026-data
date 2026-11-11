#include <bits/stdc++.h>
using namespace std;
struct qq{
	int g;
	char s;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long h=0,c=0;
	bool b=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].s;
		h+=a[i].g;
		if(a[i].g!=1) b = 0;
	}
	if(n==1){
		printf("0");
		return 0;
	}
	else if(b){
		for(int i=1;i<=h/2;i++){
			if(a[i].s!=a[n-i+1].s) c++;
		}
		printf("%d",c);
	}
	else{
		string x="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].g;j++){
				x+=a[i].s;
			}
		}
		for(int i=1;i<=h/2;i++){
			if(x[i]!=x[n-i+1]) c++;
		}
		printf("%d",c);
	}
	return 0;
}
