#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],sum,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	ll head=1,tail=n;
	ll temp1=a[head];
	ll temp2=a[tail];
	while(sum>temp1){
		if(temp1>temp2){
			if(c[head]!=c[tail]) ans+=temp2;
			sum-=temp2*2;
			temp1-=temp2;
			tail-=1;
			temp2=a[tail];
		}else if(temp1<temp2){
			if(c[head]!=c[tail]) ans+=temp1;
			sum-=temp1*2;
			temp2-=temp1;
			head+=1;
			temp1=a[head];
		}else if(temp1==temp2){
			if(c[head]!=c[tail]) ans+=temp1;
			sum-=2*temp1;
			head+=1;
			tail-=1;
			temp1=a[head];
			temp2=a[tail];
		}
	}
	cout<<ans;
	return 0;
}
