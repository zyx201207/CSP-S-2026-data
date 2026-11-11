#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read();
	int m=read(),a[N];
	for(int i=0;i<n;i++){
		a[i]=read();
	}
	sort(a,a+n);
	long long cou=0;
	int cnt=0,ans=1;
//	for(int i=0;i<n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	if(a[1]-a[0]==a[2]-a[1] && a[2]-a[1]==a[3]-a[2]){
		int d=a[1]-a[0];
		cout<<int((sqrt(1+8*m/d)-1)/2+1);
		return 0;
	}else if(a[1]==a[0]==a[2]==a[3]){
		if(m%n==0)cout<<n;
		else cout<<n-1;
		return 0;
	}
	else{
		for(int i=1;i<n;i++){
			cou=0,cnt=0;
			for(int j=i;j<n;j++){
				for(int k=i+1;k<j;k++)cou+=a[k]-a[k-1];
				if(cou>m){
					break;
				}else if(cou==m){
					cnt++;
					break;
				}else{
					cnt++;
				}
			}
			ans=max(ans,cnt);
			}
		cout<<ans;	
	}
	return 0;
}

