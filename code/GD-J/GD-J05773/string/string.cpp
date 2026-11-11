#include<bits/stdc++.h>
using namespace std;
struct c{
	int a;
	char s;
}x[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ss=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&x[i].a,&x[i].s);
	}
	int i=1,j=n;
	while(i<j){
		if(x[i].s!=x[j].s) ss+=min(x[i].a,x[j].a);
		if(x[i].a<x[j].a){
			x[j].a-=x[i].a;
			i++;
		}else if(x[i].a>x[j].a){
			x[i].a-=x[j].a;
			j--;
		}else{
			i++,j--;
		}
	}
	printf("%lld",ss);
	return 0;
}
