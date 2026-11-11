#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[200011];
char b[200011];
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&b[i]);
	}int p2=n,t2=a[n],t1=1;
	for(int p1=1;p1<p2;){
		int mi=min(a[p1]-t1+1,t2);
		if(b[p1]!=b[p2]){
			ans+=mi;
		}t1+=mi,t2-=mi;
		while(t1>a[p1]){
			t1-=a[p1++];
		}while(t2<=0){
			t2+=a[--p2];
		}
	}printf("%lld\n",ans);
}