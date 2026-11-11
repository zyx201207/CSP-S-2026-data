#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10,MAXM=3e5+10;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
int a[MAXN],n,m,len,cnt[MAXM];
vector<int> poker;
int finds(int y){
	int c=0;
	for(int i:poker){
		if(i==y)return c;
		c++;
	}
	return -1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	poker.resize(n+1);
	for(int i=1;i<=n;i++){
		len=0;
		for(int j=0;j<=n;j++)poker[j]=-1;
		for(int j=i;j<=n;j++){
			int c=finds(a[j]);
			if(c==-1){poker[++len]=a[j];}
			else{
				for(int k=c;k<=len;k++){
					poker[k]=-1;
				}
				len=c;
				//cout<<poker[c]<<" po "<<c<<" "<<len-c+1<<endl;
				poker[len]=a[j];
			}
		}
		/*
		for(int i:poker){
			if(i==-1)continue;
			//cout<<i<<" ";
			cnt[i]++;
		}
		//cout<<endl;*/
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	printf("\n");
	return 0;
}
