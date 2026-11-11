#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],s[300005],len,used[300005];
void cz1(int x){
	for(int i=x+1;i<=len;i++){
		used[s[i]]--;
		if(used[s[i]]<0)used[s[i]]=0;
		s[i]=0;
	}
	len=x;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int finds(int x){
	for(int i=1;i<=len;i++){
		if(s[i]==x)return i;
	}
	return len;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		memset(s,0,sizeof(s));
		len=0;
		for(int j=i;j<=n;j++){
			if(used[a[j]]>0)cz1(finds(a[j]));
			else used[a[j]]++,s[++len]=a[j];
		}
		for(int j=1;j<=m;j++){
			if(used[j]>0)ans[j]++;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	puts("");
	return 0;
}
