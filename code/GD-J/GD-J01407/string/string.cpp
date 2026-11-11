#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll x;
	char c;
};
int main(){
	//freopen("D://down/string/string5.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,a,sum=0,mx=0;
	cin>>n;
	vector<node> v;
	char ch,last_ch=' ';
	for(ll i=0;i<n;i++){
		cin>>a>>ch;
		if(ch==last_ch)v.back().x+=a;
		else v.push_back({a,ch});
		last_ch=ch;
		sum+=a;
		mx=max(mx,a);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n<=10||mx<=50){
		string str="";
		for(ll i=0;i<v.size();i++)for(int j=0;j<v[i].x;j++)str+=v[i].c;
		string s2=str;
		reverse(str.begin(),str.end());
		ll cnt=0;
		for(ll i=0;i<str.size();i++)if(str[i]!=s2[i])cnt++;
		cout<<cnt/2;
		return 0;
	}
	ll last=v[0].x,cnt=0;
	for(ll i=v.size()-1,pos=0;i>=0&&pos<v.size();){
		if(v[i].x>last){
			if(v[i].c!=v[pos].c)cnt+=last;
			v[i].x-=last;
			pos++;
			last=v[pos].x;
		}else if(v[i].x<last){
			if(v[i].c!=v[pos].c)cnt+=v[i].x;
			last-=v[i].x;
			i--;
		}else if(v[i].x==last){
			if(v[i].c!=v[pos].c)cnt+=v[i].x;
			pos++;
			i--;
			last=v[pos].x;
		}
	}
	cout<<cnt/2;
	return 0;
}
//sto si si ai fo orz tai nan le
