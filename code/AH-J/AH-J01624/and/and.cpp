#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		printf("%d",a[1]);
		return 0;
	}if(m==n){
		t=a[1];
		for(int i=2;i<=n;i++){
			t&=a[i];
		}
		printf("%d",t);
		return 0;
	}
	printf("%d",a[m]);
	return 0;
}
