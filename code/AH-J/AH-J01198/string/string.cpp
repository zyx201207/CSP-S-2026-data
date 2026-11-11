#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
	};
s st[200200];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int L=1,R=n;
	for(int i=1;i<=n;i++){
		cin>>st[i].a;
		cin>>st[i].c;
		}
	while(L<R){
		if(st[L].c!=st[R].c){
			if(st[L].a==st[R].a)ans+=st[L].a;
			if(st[L].a>st[R].a)ans+=st[R].a;
			if(st[L].a<st[R].a)ans+=st[L].a;
			}
		if(st[L].a==st[R].a){L++;R--;}
		else if(st[L].a>st[R].a){st[L].a-=st[R].a;R--;}
		else if(st[L].a<st[R].a){st[R].a-=st[L].a;L++;}
		}
		cout<<ans;
		return 0;
	}
