#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+105;
long long num=0,upp,downn;
long long n,top1=1,top2=1;
struct NW{
	long long a;
	char b;
}mp[maxn],ups[maxn],downs[maxn];
long long l=0,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>mp[i].a>>mp[i].b;
		num+=mp[i].a;
	}
	long long mid=num/2;
	while(upp<=mid){
		upp+=mp[l].a;
		if(upp>mid)break;
		ups[top1++]=mp[l++];
	}
	while(downn<=mid){
		downn+=mp[r].a;
		if(downn>mid)break;
		downs[top2++]=mp[r--];
	}
	if(l==r){
		NW nw;
		nw.a=mid-(upp-mp[l].a);
		nw.b=mp[l].b;
		ups[top1++]=nw;
		nw.a=mid-(downn-mp[r].a);
		downs[top2++]=nw;
	}
	long long ans=0,dw=1;
	for(int i=1;i<top1;i++){
		if(ups[i].a<downs[dw].a){
			if(ups[i].b==downs[dw].b)downs[dw].a-=ups[i].a;
			else ans+=ups[i].a,downs[dw].a-=ups[i].a;
		}else if(ups[i].a==downs[dw].a){
			if(ups[i].b==downs[dw].b){int p=1;}
			else ans+=ups[i].a;
			dw++;
		}else if(ups[i].a>downs[dw].a){
			while(true){
				if(ups[i].a<=downs[dw].a){
					if(ups[i].b==downs[dw].b)downs[dw].a-=ups[i].a;
					else ans+=ups[i].a,downs[dw].a-=ups[i].a;
					break;
				}
				if(ups[i].b!=downs[dw].b)ans+=downs[dw].a;
				ups[i].a-=downs[dw].a;
				dw++;
			}
		}
	}
	cout<<ans;
	return 0;
}
