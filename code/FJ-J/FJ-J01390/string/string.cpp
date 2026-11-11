#include<bits/stdc++.h>
using namespace std;
const int N=200001;
string s;
char c[N];
long long n,a[N],sum,ans,p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=1,r=sum,head=1,tail=n;
	while(l<=r&&head<=tail){
		bool q=(c[head]!=c[tail]);
		if(a[head]>a[tail]){
			a[head]-=a[tail];
			p=a[tail];
			a[tail]=0;
			tail--;
		}
		else if(a[head]<a[tail]){
			a[tail]-=a[head];
			p=a[head];
			a[head]=0;
			head++;
		}
		else{
			p=a[head];
			a[head]=a[tail]=0;
			head++;tail--;
		}
		if(q)ans+=p;
		l+=p;
		r=sum-l+1;
	}
	cout<<ans;
	return 0;
}
