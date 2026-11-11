#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long readll(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long a[N];
long long cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	n=read();
	m=readll();
	for(int i=0;i<n;i++){
		a[i]=readll();
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		cha[i]=a[i]-a[i-1];
	}
	long long cnt=0,num=0;
	int l=1,now=1,ans=0;
	for(int i=1;i<n;i++){
		cnt+=cha[i]*l;
		num+=cha[i];
		l++;
		if(cnt>m){
			ans=max(ans,l-1);
			while(cnt>m){
				cnt-=num;
				num-=cha[now];
				l--;
				now++;
			}
		}
	}
	ans=max(ans,l);
	cout<<ans;
	return 0;
}
