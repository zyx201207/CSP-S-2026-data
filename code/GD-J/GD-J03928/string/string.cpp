#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+100;

int len;
ll n[N];
char x[N];
ll cnt=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>len;
	for(int i=1;i<=len;i++){
		cin>>n[i]>>x[i];
	}
	int l=1,r=len;
	while(l<r){
		ll a=n[l],b=n[r];
		char c=x[l],d=x[r];
		if(a==b){
			if(c!=d) cnt+=a;
			l++,r--;
		}else{
			if(a>b){
				if(c!=d) cnt+=b;
				n[l]-=b;
				r--;
			}else{
				if(c!=d) cnt+=a;
				n[r]-=a;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

