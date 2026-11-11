#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200010];
char c[200010];
int getCh(int s){
	int t=0,sum=0;
	while(t<s){
		t+=a[sum];
		sum++;
	}
	//printf("Debug getCh--sum=%d\n",sum);
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf(" %d",&n);
	for(int i=0;i<n;i++){
		scanf(" %d",&a[i]);
		scanf(" %c",&c[i]);
	}
	long long l=0,r=0;
	for(int i=0;i<n;i++){
		//printf("%d\n",a[i]);
		r+=a[i];
	}
		
	
	//printf("AC\n");
	printf("%lld\n",r);
	while(l+1!=r) {
		while(l<=r){
			if(c[getCh(l)-1]==c[getCh(r)-1]){
				int val=min(a[getCh(l)],a[getCh(r)-1]);
				//printf("Debug a[get(l)]=%d a[get()r-1]=%d\n",a[getCh(l)-1],a[getCh(r)-1]);
				l+=val;
				r-=val;
				//printf("Debug min=%d\n",val);
				if(r<0)break;
			}
			if(c[getCh(l)-1]!=c[getCh(r)-1]){
				int val=min(a[getCh(l)],a[getCh(r)-1]);
				ans+=val;
				l+=val;
				r-=val;
				//printf("Debug !a[get(l)]=%d a[get(r)-1]=%d\n",a[getCh(l)-1],a[getCh(r)-1]);
				//printf("Debug !min=%d\n",val);
				if(r<0)break;
			}
		//printf("Debug l=%d -> %c\n",l,c[getCh(l)]);
		//printf("Debug r=%d -> %c\n",r,c[getCh(r)-1]);
		//printf("Debug ans=%d\n",ans);
		if(r<0)break;
		}
		break;
	}
	printf("%lld",ans);
	return 0;
} 
