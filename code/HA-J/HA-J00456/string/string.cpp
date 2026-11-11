#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);		
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll n;
    vector<char>lis;
    cin>>n;
    ll z=0,s,c,old;
    char m;
    for(int yy=1;yy<=n;yy++){
    	cin>>s>>c;
        old=s;
    	z=max(old,z);
    	m=c;
    	for(int i=0;i<s;i++){
    		lis.push_back(c);
		}
	}
	ll sum=0;
	for(int v=0;v<lis.size();v++){
		if(lis[v]!=m){
			lis[v]=m;
			sum++;
		}
	}
	int i=1;
	ll ans=0;
	ll mm,zz=0;
	for(int q=0;q<ll(lis.size());q++){
		for(int j=i;j<ll(lis.size());i++,j++){
			if(lis[j]!=m){
				lis[j]=m;
				ans++;
			}
		}
		mm = ans;
		zz=min(mm,zz);
	}
	
	cout<<zz;
	return 0;
}
