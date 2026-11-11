#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],f[300005],c[500005],p[300005],cnt;
bool A(){
	int f=1;
	for(int i=1;i<n;i++)if(a[i]>a[i+1])f=0;
	return f;
}
bool B(){
	return m==2;
}
void work(int st){
	memset(f,0,sizeof f);
	memset(p,0,sizeof p);
	cnt=0;
	for(int i=st;i<=n;i++){
		int ps=a[i];
		if(p[ps]){
			while(cnt){
				if(!p[ps])break;
				p[c[cnt]]--;
				cnt--;	
			}
		}
		c[++cnt]=ps;
		p[ps]++;
	}
	while(cnt){
		int x=c[cnt];
		//cout<<x<<" ";
		f[x]++;
		cnt--;
	}
	for(int i=1;i<=m;i++)ans[i]+=(f[i]>0);
	//cout<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(A()){
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1])cout<<i-1<<" "; 
		}
		cout<<n;
		return 0;
	}
	if(B()){
		int x=0,y=0;
		if(a[n]==1){
			x=n;
			for(int i=1;i<=n;i++)y+=(a[i]==2);
		}else{
			y=n;
			for(int i=1;i<=n;i++)x+=(a[i]==1);
		}
		cout<<x<<" "<<y<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)work(i);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
游记：
这次T123不是很难吧，应该是最简单的了，但我还是不会做（
最后一次考j组了，之后可能是打S或者直接AFO了
学了两三年也没什么长进 颤颤巍巍见自己了属于是 
在csp开茶话会的来 吃了67个薯条（（
luogu 786662 rp++ 
MJ
*/
