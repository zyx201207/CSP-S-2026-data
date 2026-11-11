#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char c[N];
long long n,cnt,a[N],sum,l;
long long l1=1,l2,ans,z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//n=1
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
	long long m=sum;
	if(sum%2==0) sum/=2;
	else sum=sum/2+1;
	z=sum;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		if(cnt>sum){
			l=i,cnt-=sum;
			break;
		}
	}
	l2=n;
	while(z!=m&&l1!=l2){
		m-=min(a[l1],a[l2]);
		if(c[l1]!=c[l2]){
			if(a[l1]>a[l2]){
				ans+=a[l2];
				a[l1]-=a[l2],l2--;
			}
			else if(a[l1]<a[l2]){
				ans+=a[l1];
				a[l2]-=a[l1],l1++;
			}
			else ans+=a[l1],l1++,l2--;
		}
		else{
			if(a[l1]>a[l2]) a[l1]-=a[l2],l2--;
			else if(a[l1]<a[l2]) a[l2]-=a[l1],l1++;
			else l1++,l2--;
		}
		
	}
	cout<<ans;
	//3 2 a 2 b 1 c
	//6 1000000 a 1000000 b 1000000 c 1000000 d 1000000 e 1000000 f
	//5 3 a 2 c 2 b 2 c 2 b
	//2 2 a 3 a
	return 0;
}
