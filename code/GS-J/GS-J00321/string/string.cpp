#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct N{
	ll num;
	char l;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    ll n;
    cin>>n;
    ll sum=0;
    vector<N> a(n+3);
    for(int i=1;i<=n;i++){
    	cin>>a[i].num>>a[i].l;
    	sum+=a[i].num;
	}
	ll mid=sum/2;
	if(sum&1){
		ll sum2=0;
		for(int i=1;i<=n;i++){
			sum2+=a[i].num;
			if(sum2>=mid){a[i+1].num-=1;break;}
		}
	}
	ll sum2=0,front,rear;
	for(int i=1;i<=n;i++){
		sum2+=a[i].num;
		if(sum2>=mid){rear=i;front=i+1;break;}
	}
	ll ans=0;
	while(front<=n&&rear>0){
		if(a[front].l==a[rear].l){
			if(a[front].num>a[rear].num){
				a[front].num-=a[rear].num;
				rear--;
			}else if(a[front].num==a[rear].num){
				front++;
				rear--;
			}else{
				a[rear].num-=a[front].num;
				front++;
			}
		}else{
			if(a[front].num>a[rear].num){
				ans+=a[rear].num;
				a[front].num-=a[rear].num;
				rear--;
			}else if(a[front].num==a[rear].num){
				ans+=a[rear].num;
				front++;rear--;
			}else{
				ans+=a[front].num;
				a[rear].num-=a[front].num;
				front++;
			}
		}
	}
	cout<<ans;
    return 0;
}










