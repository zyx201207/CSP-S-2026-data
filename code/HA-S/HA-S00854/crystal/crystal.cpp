#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005]; 
long long m;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int sum=0;
	for(int i=n;i>=1;i--){
		int t=0;
		for(int j=i;j>=1;j--){
			if(m-a[i]+a[j]>=0){
				t++;
				m-=a[i]-a[j];
			}
		}
		sum=max(sum,t);
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
