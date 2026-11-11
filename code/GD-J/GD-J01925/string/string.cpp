#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,v[100000],ans=0,w[100000];
string al;
ll f(ll x ,ll y){
	return (x%y==0?x/y:x/y+1);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   // scanf("%lld,%lld,%lld,%lld",a,al,b,bl);
   cin>>n;
   if(n==1){
   	cout<<0;
   	return 0;
   }
   char m;ll o=0;
    for(ll i=1;i<=n;i++){
    	char x;
    	cin>>v[i]>>x;
    	if(i==1)m=x;
    	if(i!=1 and x!=m)o++;
		al=al+x;
    	ans=ans+v[i];
    	w[i]=v[i]/2;
	}
	if(o==0){
	cout<<0;return 0;}
	ll p=0;
	ll q=0;
	ll e=0;
	for(ll i=f(ans,2);i<=ans;i++){
		
		while(w[q]<i or w[e]<i-f(ans,2)){
			if(w[q]<i)q++;
			if(w[e]<i-f(ans,2))e++;
		}	
	//	cout<<q<<" "<<e<<endl;
			if(al[q]!=al[e])p++;
	}
	cout<<p-1;
    return 0;
}
