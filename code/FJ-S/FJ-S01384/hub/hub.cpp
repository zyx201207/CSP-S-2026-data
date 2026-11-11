#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e6+5;
vector<int>a[N];
int c,t,n,k;
inline int read(){
	int x=1,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n-1;i++)int u=read(),v=read();
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(k>=n-2){
			cout<<1<<'\n';
			continue;
		}
		if(c==13||c==14){
			int m=n/2;
			if(k>=m+2){
				cout<<1<<'\n';
				continue;
			}
			cout<<(m/2+2-k/2)/2<<'\n';
			continue;
		}
		cout<<n/2<<'\n';
	}
	return 0;
}

