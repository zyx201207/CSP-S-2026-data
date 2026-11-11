#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n;
const int N=2e5+5;
ll ans;
struct Node{
	ll Length;
	char c;
}a[N];
int q[N];
int head,tail;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d %c",&a[i].Length,&a[i].c);
	head=1,tail=0;
	for(int i=1;i<=n;i++)q[++tail]=i;
	while(head<=tail){
		Node x=a[q[head]],y=a[q[tail]];
		if(x.Length==y.Length&&x.c==y.c)head++,tail--;
		else if(x.Length!=y.Length&&x.c==y.c){
			int MIN=min(x.Length,y.Length);
			if(MIN==x.Length)head++,a[q[tail]].Length=y.Length-x.Length;
			else tail--,a[q[head]].Length=x.Length-y.Length;
		}else{
			int MIN=min(x.Length,y.Length);
			if(MIN==x.Length)head++,a[q[tail]].Length=y.Length-x.Length;
			else tail--,a[q[head]].Length=x.Length-y.Length;
			ans+=MIN;
		}
	}
	printf("%ld",ans);
	return 0;
}
