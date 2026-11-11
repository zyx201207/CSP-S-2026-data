#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int b[300005],t,c[300005],t2;
bool check(){
	for(int i=1;i<=t;i++){
		if(b[i]!=-1)return 0;
	}
	return 1;
}
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		t=0;
		for(int j=i;j<=n;j++)b[++t]=a[j];
		t2=0;
		for(int j=1;j<=t;j++){
			bool f=0;
			int pos=0;
			for(int k=1;k<=t2;k++){
				if(c[k]==b[j]){
					f=1;
					pos=k;
					break;
				}
			}
			if(f){
				t2=pos;
			}
			else{
				c[++t2]=b[j];
			}
//			for(int k=1;k<=t2;k++)cout<<c[k]<<" ";
//			cout<<"\n";
		}
		for(int j=1;j<=t2;j++)ans[c[j]]++;
//		for(int k=1;k<=t2;k++)cout<<c[k]<<" ";
//			cout<<"\n";
//		cout<<"\n"; 
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
