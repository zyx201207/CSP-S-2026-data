#include<bits/stdc++.h>
#include<iostream>
#include<string>
#define ll long long
using namespace std;
ll a,b,c,d,cnt=0,ds=0,l,r,t,m,n,ans;
struct node{
	ll x;
	string s;
};
ll cmp(ll x,ll s){
	if((2*n-(x+s)*n)!=x){
		return x;
		cnt++;
	}
	else if(x*n==s/n)return (x+2)/s;
	else return s;
	}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>a>>b>>node.s;
	for(int i=1;i<=n;i++){
		cin>>d;
		cnt+=d;
	}
	cin>>c;
	ll k=n;
	while(k<=cnt){
		if(b*k%2==0&&b==a*2){
			cnt*=b*k;
		    cnt++;
		}
		else if(b*k%3==0&&b==a*3){
			cnt*=b*k*2;
			cnt+=2;
		}
		else if(b*k%3==0&&b==a*4){
			cnt/=b;
			cnt+=node.x;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
