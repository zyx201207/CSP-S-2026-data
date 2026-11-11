#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll a;
	char c;
};
Node s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,x,k=1;
	char y;
	cin>>n;
	for(ll i=1;i<=n;i++){
		if(i==1) cin>>s[i].a>>s[i].c;
		else{
			cin>>x>>y;
			if(y==s[k].c) s[k].a+=x;
			else{
				s[++k].a=x;
				s[k].c=y;
			}
		}
	}
	if(k==1){
		cout<<"0";
		return 0;
	}
	ll i=1,sum=0;
	while(i<k){
		if(s[i].c!=s[k].c){
			sum+=min(s[i].a,s[k].a);
		}
		if(s[i].a<s[k].a){
			s[k].a-=s[i].a;
			i++;
		}
		else if(s[i].a==s[k].a){
			k--;
			i++;
		}
		else if(s[i].a>s[k].a){
			s[i].a-=s[k].a;
			k--;
		}
	}
	cout<<sum;
	return 0;
}
