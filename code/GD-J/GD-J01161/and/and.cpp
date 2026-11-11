#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,K=30;
int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s;
}
int n,m,cnt[K],lst,now;
ll ans=0;
vector<int> ch[2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//double st=clock();
	n=read(),m=read();
	lst=0,now=1;
	for(int i=1;i<=n;i++){
		int x=read();
		ch[lst].push_back(x);
	}
	for(int i=K;~i;i--){
		ch[now].clear();
		for(int j=0;j<ch[lst].size();j++){
			int v=ch[lst][j];
			if(v&(1<<i)){
				//cout<<(1<<i)<<" "<<v<<endl;
				ch[now].push_back(v);
			}
		}
		if(ch[now].size()>=m){
			//cout<<(1<<i)<<"a\n";
			ans|=1ll<<i;
			swap(now,lst);
		}
		else continue;
	}
	//double ed=clock();
	cout<<ans;
	return 0;
	//printf("%0.lf",ed-st);
}
/*4 2
12 12 15 3*/
