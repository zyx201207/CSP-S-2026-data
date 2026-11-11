#include<bits/stdc++.h>
using namespace std;
int n,a[200100];
char c[200100];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		scanf(" %c",&c[i]);
	}
	long long t1=0,t2=0;
	for(int i=1,j=n;i<j;){
		if(t1==0) t1=a[i];
		if(t2==0) t2=a[j];
		if(t1>t2){
			t1-=t2;
			if(c[i]!=c[j]) cnt+=t2;
			t2=0;
			j--;
		}
		if(t1<t2){
			t2-=t1;
			if(c[i]!=c[j]) cnt+=t1;
			t1=0;
			i++;
		}
		if(t1==t2){
			if(c[i]!=c[j]) cnt+=t1;
			t1=t2=0;
			i++;j--;
		}
	}
	printf("%lld",cnt);
	return 0;
}

