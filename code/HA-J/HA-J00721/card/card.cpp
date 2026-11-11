#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],d[N],c[N],ans[N],res;
void push(int x){
	if(d[x]){
		for(int i=res;i>d[x];i--){
			if(d[c[i]]==i) d[c[i]]=0;
			c[i]=0;
		}
		res=d[x];
	}else{
		res++;
		c[res]=x;
		d[x]=res;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0) b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
//		for(int j=1;j<=n;j++){
//			c[j]=a[j];
//		}
//		for(int j=1;j<=m;j++) d[j]=b[j];
		
//		for(int i=1;i<=n;i++) cout<<c[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=m;i++) cout<<d[i]<<" ";
//		cout<<endl;
//		cout<<endl;
		res=n;
		for(int j=i;j<=n;j++){
//			cout<<a[j]<<" ";
			push(a[j]);
		
//			for(int j=1;j<=res;j++){
//				cout<<c[j]<<" ";
//			}
//			cout<<endl;
		
		}
//		cout<<endl;
		for(int j=1;j<=res;j++){
//			cout<<c[j]<<" ";
			ans[c[j]]++;
		}
//		cout<<endl;
//		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	
	return 0;
}
