#include<iostream>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],pos[M],fp[M],cnt[M],ans[M];
inline int read(){
	int f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	bool flag=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		cnt[a[i]]++;
		if(!fp[a[i]])fp[a[i]]=i;
		if(a[i]<a[i-1])flag=0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(flag){
		for(int i=1;i<=m;i++)cout<<fp[i]-1+cnt[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)pos[j]=0;
		for(int j=i;j<=n;j++){
			if(pos[a[j]]){
				for(int h=pos[a[j]];h<j;h++){
					if(pos[a[h]]){
						pos[a[h]]=0;
						ans[a[h]]--;
					}
				}
			}
			ans[a[j]]++;
			pos[a[j]]=j;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';	
	return 0;
}
