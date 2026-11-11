#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
inline long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,a[N];
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		cin>>a[i]>>c[i];
	int i=1,j=n,x=a[1];
	while(i<j){
		if(x-a[j]>0){
			if(c[i]!=c[j]) ans+=a[j];
			x-=a[j];
			j--;
		}
		else if(x-a[j]==0){
			if(c[i]!=c[j]) ans+=x;
			i++,j--;
			x=a[i];
		}
		else if(x-a[j]<0){
			if(c[i]!=c[j]) ans+=x;
			a[j]-=x;
			i++;
			x=a[i];
		}
	}
	cout<<ans;
	return 0;
}

