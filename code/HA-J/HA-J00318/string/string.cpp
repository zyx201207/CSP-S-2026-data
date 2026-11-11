#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
	int shu,zi;
};
Node num[200005];
ll n,f,ans=0;
void TBS(){
	ll j=n,i=1;
	while(1){
		if(j==1 && i==n){
			return;
		}
		if(f==0){
			return;
		}
		if(num[i].shu==0){
			i++;
		}
		if(num[j].shu==0){
			j--;
		}
		if(num[i].zi==num[j].zi){
			if(num[i].shu>num[j].shu){
				f-=num[j].shu;
				num[i].shu-=num[j].shu;
				num[j].shu=0;
			}
			if(num[i].shu<num[j].shu){
				f-=num[i].shu;
				num[j].shu-=num[i].shu;
				num[i].shu=0;
			}
			if(num[i].shu==num[j].shu){
				f-=num[j].shu;
				num[j].shu=0;
				num[i].shu=0;
			}
		}
		if(num[i].zi!=num[j].zi){
			if(num[i].shu>num[j].shu){
				num[i].shu-=num[j].shu;
				f-=num[j].shu;
				ans+=num[j].shu;
				num[j].shu=0;
			}
			if(num[i].shu<num[j].shu){
				ans+=num[i].shu;
				f-=num[i].shu;
				num[j].shu-=num[i].shu;
				num[i].shu=0;
			}
			if(num[i].shu==num[j].shu){
				ans+=num[j].shu;
				f-=num[i].shu;
				num[j].shu=0;
				num[i].shu=0;
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		f+=a;
		num[i].shu=a;
		num[i].zi=c;
	}
	ll d=f/2;
	TBS();
	cout<<ans;
}
