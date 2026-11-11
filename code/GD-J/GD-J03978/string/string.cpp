#include<bits/stdc++.h>
using namespace std;
long long l,n,le=1,ri,mid,cnt=1,ans;
int i,j;
char b;
struct str{
	long long a;
	char c;
}s[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	mid=l/2;
	for(i=1;i<=l;i++){
		cin>>n>>b;
		if(s[i-1].c==b){
			s[i-1].a+=n;
			break;
		}else{
			s[cnt].a=n;
			s[cnt].c=b;
			cnt++;
		}
	}
	ri=cnt-1;
	while(le<ri){
		cout<<le<<" "<<ri<<endl;
		if(s[le].a>s[ri].a){
			if(s[le].c!=s[ri].c) ans+=s[ri].a;
			s[le].a-=s[ri].a;
			ri--;
		}else if(s[le].a<s[ri].a){
			if(s[le].c!=s[ri].c) ans+=s[le].a;
			s[ri].a-=s[le].a;
			le++;
		}else{
			if(s[le].c!=s[ri].c) ans+=s[le].a;
			le++;
			ri--;
		}
		cout<<ans<<endl<<endl;
	}
	cout<<ans;
	return 0;
}
