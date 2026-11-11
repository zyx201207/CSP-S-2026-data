#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
int a[N];
int xiang(int a[]){
	int res=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			res++;
		}
	}
	return res;
}
long long sum(int a,int b){
	if(a>=b){
		return a-b;
	}
	else{
		return 0;
	}
}
bool cmp(int a,int b){
	return a<b;
}
long long sun(int n,long long m,int a[]){
	long long res=-1e9; 
	int h=n;
	for(long long i=a[0];i<=a[h-1];i++){
		while(n){
			long long summ=0,t=xiang(a);
			for(int j=1;j<n;j++){
				summ+=sum(a[j],i);
			}
			if(summ<=m){
				t+=n;
				res=max(res,t);
			}
			n--;
		}
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	long long res=sun(n,m,a);
	printf("%lld",res);
	return 0;
}
