#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=2e6+5;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,q,n,flag;
	long long x[N],d,cnt=0;
	cin>>t>>q;
	while(q--){
		n=read(),d=read();
		for(int i=0;i<n;i++){
			x[i]=read();
			if(i>0){
				if(x[i]-x[i-1]>d){
					flag=i;
				}
			}
		}
		n=flag;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(x[j]-x[i]<=d)continue;
				if(x[j]-x[i]<d && j-i==1)cnt++;
			}
		}
		cout<<cnt<<endl;cnt++;
	}
	return 0;
}

