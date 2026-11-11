#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
	int a;
	char c;
}s1[N],s2[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s1[i].a>>s1[i].c;
		s2[n-i+1].a=s1[i].a;
		s2[n-i+1].c=s1[i].c;
	}
	int ans=0,j=1;
	for(int i=1;i<=n;){
		if(i+j>n)break;
		if(s1[i].a==s2[j].a&&s1[i].c==s2[j].c){
			i++,j++;continue;
		}
		if(s1[i].a==s2[j].a)ans+=s1[i].a,i++,j++;
		else{
			if(s1[i].a>s2[j].a)ans+=(s1[i].c==s2[j].c?0:s2[j].a),s1[i].a-=s2[j].a,j++;
			else ans+=(s1[i].c==s2[j].c?0:s1[i].a),s2[j].a-=s1[i].a,i++;
		}
	}
	cout<<ans;
	return 0;
}

