#include<bits/stdc++.h>
using namespace std;
struct STR{
	int a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}int l=1,r=n;
	while(1){
		if(l>r)break;
		int comp=min(s[l].a,s[r].a);
		if(s[l].c!=s[r].c)ans+=comp;
		if(s[l].a>s[r].a){
			s[l].a-=comp;
			r--;
		}else if(s[l].a<s[r].a){
			s[r].a-=comp;
			l++;
		}else{
			r--;l++;
		}
	}cout<<ans;
	return 0;
} 
