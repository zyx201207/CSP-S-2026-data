#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
char b[N];
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		getchar();
		b[i]=getchar();
	}
	int x1=0,x2=n-1;
	while(x1<x2){
		if(b[x1]==b[x2]){
			if(a[x1]==a[x2]){
				x1++,x2--;
			}
			else if(a[x1]>a[x2]){
				a[x1]-=a[x2];
				x2--;
			}
			else{
				a[x2]-=a[x1];
				x1++;
			}
		}
		else{
			if(a[x1]==a[x2]){
				s+=a[x1];
				x1++,x2--;
			}
			else if(a[x1]>a[x2]){
				s+=a[x2];
				a[x1]-=a[x2];
				x2--;
			}
			else{
				s+=a[x1];
				a[x2]-=a[x1];
				x1++;
			}
		}
	}
	printf("%lld",s);
	return 0;
}
