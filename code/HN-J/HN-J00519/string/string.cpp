#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum=1,ans;
struct node{
	int a,h,t;
	char c;
}jt[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		jt[i].h=sum;
		cin>>jt[i].a>>jt[i].c;
		jt[i].t=sum+jt[i].a-1;
		sum+=jt[i].a;
	}
	int q=1,h=n;
	while(q<h){
		if(jt[q].a<jt[h].a){
			if(jt[q].c!=jt[h].c){
				ans+=jt[q].a;
			}
			jt[h].a-=jt[q].a;
			q++;
			continue;
		}
		if(jt[q].a>jt[h].a){
			if(jt[q].c!=jt[h].c){
				ans+=jt[h].a;
			}
			jt[q].a-=jt[h].a;
			h--;
			continue;
		}
		if(jt[q].c!=jt[h].c){
			ans+=jt[q].a;
		}
		q++;
		h--;
	}
	cout<<ans;
	return 0;
} 
