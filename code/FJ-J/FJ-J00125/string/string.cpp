#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,a[N],ans=0;
char ch[N];
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
		cin>>ch[i];
	}
	long long j=n;
	for(int i=1;i<=n;i++){
		while(a[i]>0){
				if(a[i]>=a[j]){
					if(ch[i]!=ch[j]){
						ans+=a[j];
						a[i]-=a[j];
						a[j]=0;
						j--;
					}else{
						a[i]-=a[j];
						a[j]=0;
						j--;
					}
				} else{
					if(ch[i]!=ch[j]){
						ans+=a[i];
						a[j]-=a[i];
						a[i]=0;
					}else{
						a[j]-=a[i];
						a[i]=0;
					}
				}
		}	
	}
	cout<<ans;
	return 0; 
}
