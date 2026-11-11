#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll t,n;
char a;
struct node{
	ll num;
	char c;
};
vector<node> v;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	bool key=0;
	while(t--){
		scanf("%lld",&n);
		cin>>a;
		if(n<=50) for(ll i=1;i<=n;i++) s+=a;
		else key=1;
		node temp;
		temp.num=n,temp.c=a;
		v.push_back(temp);
	}
	if(!key){
		ll sum=0,len=s.size();
		if(len%2==0){
			for(ll i=0;i<len/2;i++) if(s[i]!=s[len-i-1]) sum++;
		}else{
			for(ll i=0;i<len/2+1;i++) if(s[i]!=s[len-i-1]) sum++;
		}
		cout<<sum;
	}else{
		ll len=v.size();
		for(ll i=0;i<len/2;i++){
			if(v[i].c==v[len-1-i].c){
				ll temp=min(v[i].num,v[len-i-1].num);
				v[i].num-=temp;
				v[len-1-i].num-=temp;
			}else break;
		}
		for(ll i=len-1;i>=0;i--) if(v[i].num==0) v.erase(v.begin()+i);
		
		ll sum=0;
		len=v.size();
		for(ll i=0;i<len/2;i++){
			ll ch=0,temp=v[i].num;
			for(ll j=len-i-1;j>=i;j--){
				 if(temp>v[j].num){
					 ch+=v[j].num;
					 temp-=v[j].num;
				 }else{
					 ch+=temp;
					 break;
				 }
			}
			sum+=ch;
		}
		cout<<sum;
	}
	return 0;
}
