#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],cha,sum,num,ans=-1;
queue<long long>q;
long long rsum(){
	return num*cha-sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	//cout<<"T";
	for(int i=1;i<=n;i++){
		q.push(a[i]);
		sum+=a[i];num++;cha=a[i];
		//cout<<i<<"J "<<rsum()<<" "<<a[i]<<" "<<sum<<" "<<num<<"\n";
		while(rsum()>m){
			int v=q.front();
			q.pop();
			sum-=v;
			num--;
		}
		//cout<<i<<"S "<<rsum()<<" "<<a[i]<<" "<<sum<<" "<<num<<"\n";
		ans=max(ans,num);
	}
	printf("%lld",ans);
	return 0;
}
