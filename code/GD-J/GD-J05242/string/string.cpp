#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b;
int s2[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	ll i=1;
	while(a--){
		int c;
		string d;
		cin>>c>>d;
		s2[i]=d[0]-'a'+1;
		i+=c;
	}
	i;
	for(int y=1;y<=i;y++) if(s2[y]==0) s2[y]=s2[y-1];
	if(a%2==0){
		for(int y=1;y<=i/2;y++){
			for(int j=i;j>i/2;j++){
				if(s2[i-y]==s2[y]) continue;
				b++;
			}
		}
	}else{
		for(int y=1;y<=i/2;y++){
			if(s2[i-y]==s2[y]) continue;
			b++;
		}
	}
	cout<<b;
	return 0;
}
