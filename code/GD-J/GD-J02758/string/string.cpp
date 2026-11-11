#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
struct node{
	int a;
	char c;
}l[maxn];
int hd=0,tl=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i].a>>l[i].c;
		//len+=a;
	}
	hd=1,tl=n;
	while(hd<tl){
		if(l[hd].c==l[tl].c){
			int mn=min(l[hd].a,l[tl].a);
			l[hd].a-=mn;
			l[tl].a-=mn;
			if(!l[hd].a) ++hd;
			if(!l[tl].a) --tl;
		}else if(l[hd].a==l[tl].a){
			ans+=l[hd].a;
			++hd;
			--tl;
		}else{
			int mn=min(l[hd].a,l[tl].a);
			l[hd].a-=mn;
			l[tl].a-=mn;
			ans+=mn;
			if(!l[hd].a) ++hd;
			if(!l[tl].a) --tl;
		}
	}
	cout<<ans;
	return 0;
}
