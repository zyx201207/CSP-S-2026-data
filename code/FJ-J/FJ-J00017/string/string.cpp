#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
inline long long read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
    	if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
long long n,a[N],ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>c[i];
	}
	int id=n;
	for(int i=1;i<id;i++){
		while(i<id){
			a[i]-=a[id];
			if(c[i]!=c[id]&&a[i]>=0){
				ans+=a[id];
			}
			else if(c[i]!=c[id])ans+=a[id]+a[i];
			if(a[i]<0){
				a[id]=a[id]-a[id]-a[i];
			}
			id--;
			if(a[i]<0){
				id++;
			}
			if(a[i]<=0)break;
		} 
	}
	cout<<ans;
	return 0;
}

