#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct A{
	long long a;
	char c;
}st[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].a>>st[i].c;
		if(st[i].c==st[i-1].c&&i>1){
			st[i-1].a+=st[i].a;
			i--,n--;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}if(n==2){
		long long x=min(st[1].a,st[2].a);
		cout<<x;
		return 0;
	}
	for(int i=1,j=n;i<j;){
		if(st[i].a==st[j].a){
			if(st[i].c!=st[j].c)ans+=st[i].a;
			i++,j--;
		}else if(st[i].a<st[j].a){
			if(st[i].c!=st[j].c)ans+=st[i].a;
			st[j].a-=st[i].a;
			i++;
		}else{
			if(st[i].c!=st[j].c)ans+=st[j].a;
			st[i].a-=st[j].a;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
