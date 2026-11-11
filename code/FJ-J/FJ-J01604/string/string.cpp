#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string x;
	string y;
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		scanf("%s",&c[i]);
		for(int j=0;j<a[i];j++){
			x+=c[i];
		}
	}
	for(int i=x.size()-1;i>=0;i--){
		y+=x[i];
	}
	for(int i=0;i<(x.size()+1)/2;i++){
		if(y[i]!=x[i]){
			sum++;
		}
	}
	printf("%lld",sum);
	return 0;
} 
