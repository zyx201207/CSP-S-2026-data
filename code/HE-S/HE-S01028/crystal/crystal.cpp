#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,sum=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1]-a[i];
	}
	sort(a,a+n-1);
	for(int i=0,x=0;i<=n-1;i++){
		if(m-a[i]>=0){
			sum++;
			x+=a[i];
			m-=x;
		}else{
			break;
		}
	}
	printf("%d",sum);
	return 0;
} 
