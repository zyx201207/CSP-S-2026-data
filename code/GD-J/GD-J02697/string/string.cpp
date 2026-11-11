#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct ss{
	long long sum=0;
	char s;
};
const int N=2e5+10;
ss a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].sum);
		cin>>a[i].s;
	}
	int head=1,tail=n;
	while(head<tail){
		if(a[head].sum<a[tail].sum){
			a[tail].sum-=a[head].sum;
			if(a[tail].s!=a[head].s){
				ans+=a[head].sum;
			}
			a[head].sum=0;
			head++;
		}else if(a[head].sum>a[tail].sum){
			a[head].sum-=a[tail].sum;
			if(a[tail].s!=a[head].s){
				ans+=a[tail].sum;
			}
			a[tail].sum=0;
			tail--;
		}else {
			if(a[tail].s!=a[head].s){
				ans+=a[head].sum;
			}
			a[tail].sum=0;
			a[head].sum=0;
			tail--;
			head++;
		}
	}
	printf("%lld",ans);
	return 0;
}
