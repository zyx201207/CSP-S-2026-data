#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005],in[300005];
bool last[300005];
vector<int> ve[300005];
queue<int> qu;

int read(){
	int num=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}
	return num;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=n;i>=1;i--){
		num[a[i]]++;
		if(last[a[i]]) continue;
		last[a[i]]=1;
		if(i==n) continue;
		ve[a[i]].push_back(a[i+1]);
		in[a[i+1]]++;
	}
	for(int i=1;i<=m;i++) if(!in[i]) qu.push(i);
	while(qu.size()){
		int x=qu.front(); qu.pop();
		for(int i=0;i<ve[x].size();i++){
			int y=ve[x][i];
			num[y]+=num[x]; in[y]--;
			if(!in[y]) qu.push(y);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}
