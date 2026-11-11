#include<bits/stdc++.h>
using namespace std;

const int N=200005;

long long ans;
int n,len[N];
char c[N];

char read(){
	char ch=getchar();
	while(ch<'a'||ch>'z')	ch=getchar();
	while(ch>='a'&&ch<='z') return ch;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		c[i]=read();
	}
	long long l=1,r=n,rl=len[1],rr=len[n];
	char rcl=c[1],rcr=c[n];
	while(l<r){
		if(rl<rr){
			if(rcl!=rcr) ans+=rl;
			rr-=rl;
			l++;
			rl=len[l];
			rcl=c[l];
			
		}
		else if(rl==rr){
			if(rcl!=rcr) ans+=rl;
			l++;
			r--;
			rl=len[l];
			rcl=c[l];
			rr=len[r];
			rcr=c[r];
		}
		else{
			if(rcl!=rcr) ans+=rr;
			rl-=rr;
			r--;
			rr=len[r];
			rcr=c[r];
			
		}
	}
	cout<<ans<<endl;
}
