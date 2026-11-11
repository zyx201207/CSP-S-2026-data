#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct sss{
	long long a;
	char b;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	long long L=1,R=n;
	while(L<R){
		if(s[L].a>s[R].a){
			if(s[L].b!=s[R].b){
				sum+=s[R].a;
			}
			s[L].a-=s[R].a;
			R--;
		}else if(s[L].a<s[R].a){
			if(s[L].b!=s[R].b){
				sum+=s[L].a;
			}
			s[R].a-=s[L].a;
			L++;	
		}else{
			if(s[L].b!=s[R].b){
				sum+=s[R].a;
			}
			L++;
			R--;
		}
	}cout<<sum;
	return 0;
}
