#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>ch[i];
	}
	ll l=a[1],li=1,r=a[n],ri=n;
	ll ans=0;
	while(ri-li>0){
		if(r>l){
			if(ch[li]!=ch[ri])
				ans+=l;
			r=r-l,l=a[++li];
		}
		else if(l>r){
			if(ch[li]!=ch[ri])
				ans+=r;
			l=l-r,r=a[--ri];
		}
		else{
			if(ch[li]!=ch[ri])
				ans+=l;
			l=a[++li],r=a[--ri];
		}
	}
	cout<<ans;
	
	
 return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a	
1000000000 b
1000000000 b
1000000000 b
*/
