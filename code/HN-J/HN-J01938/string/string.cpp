#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Str{
	long long len;
	char c;
}s[N];
int tot=0;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		if(i==1)s[++tot]={a,c};
		else if(c!=s[tot].c)s[++tot]={a,c};
		else s[tot].len+=a; 
	}
	int l=1,r=tot;
	long long ans=0;
	while(l<r){
		if(s[l].len==s[r].len){
			if(s[l].c!=s[r].c)ans+=s[l].len;
			l++,r--;
		}else{
			long long tmp=min(s[l].len,s[r].len);
			if(s[l].c!=s[r].c){
				ans+=tmp;
			}
			s[l].len-=tmp;
			s[r].len-=tmp;
			if(s[l].len==0)l++;
			if(s[r].len==0)r--; 
		}
	}
	cout<<ans;
	return 0;
}

