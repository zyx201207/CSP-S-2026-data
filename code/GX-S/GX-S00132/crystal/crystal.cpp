#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100];
long long s[10000][10000];
long long ans=0;
void shuru(){
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
}
void jisuan(){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			s[i][j]=a[i]-a[j];
		}
	}
	/*
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%lld ",s[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i=n-1;i>0;i--){
		int aaa=0;
		for(int j=i-1,o=1;j>=0;j--,o++){
//			printf("aaa=%lld s[i][j]=%lld i=%d j=%d\n",aaa+s[i][j],s[i][j],i,j);
			if(aaa+s[i][j]>m){
				if(o>ans){
					ans=o;
				}
				break;
			}
			if(aaa+s[i][j]==m){
				if(o>=ans){
					ans=o+1;
				}
				break;
			}
			aaa+=s[i][j];
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	shuru();
	jisuan();
	printf("%lld",ans);
	return 0;
}
