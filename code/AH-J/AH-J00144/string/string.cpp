#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len;
int m[200005];
char a[200005];
vector<int> s[27],e[27];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&m[i]);
		cin>>a[i];
		len+=m[i];
	}
	long long prlen=0,pc=0;
	if(len%2LL==1LL) pc=1LL;
	long long ans=len-len/2LL-pc;
	for(int i = 1;i <= n;i++){
		prlen+=m[i];
		if(prlen<=(len/2LL+pc)){
			s[a[i]-'a'].push_back(prlen-m[i]+1LL);
			e[a[i]-'a'].push_back(prlen);
		}else{
			if(prlen-m[i]+1LL<=len/2LL+pc){
				ans-=min(len/2LL+pc-(prlen-m[i]+1LL),prlen-len/2LL-pc);
				if(len-prlen+1LL==prlen-m[i]+1LL)continue;
				for(int j = 0;j < (int)s[a[i]-'a'].size();j++){
					if(s[a[i]-'a'][j]>len-(len/2+pc+1LL))break;
					if(s[a[i]-'a'][j]<=len-prlen+m[i]){
						ans-=max(min(e[a[i]-'a'][j],len-(len/2+pc+1LL))-max(s[a[i]-'a'][j],len-prlen+1LL)+1LL,0LL);
					}
				}
			}else{
				for(int j = 0;j < (int)s[a[i]-'a'].size();j++){
					if(s[a[i]-'a'][j]>len-prlen+m[i])break;
					if(s[a[i]-'a'][j]<=len-prlen+m[i]){
						ans-=max(min(e[a[i]-'a'][j],len-prlen+m[i])-max(s[a[i]-'a'][j],len-prlen+1LL)+1LL,0LL);
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
