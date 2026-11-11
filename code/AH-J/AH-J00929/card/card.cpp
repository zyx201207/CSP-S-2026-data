#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],x[N],s[N];
bool f[N];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	memset(f,0,sizeof(f));
	memset(x,0,sizeof(x));
	int t=1;
	for(int j=i;j<=n;j++){
		if(f[a[j]]==0){
			x[t]=a[j];
			f[a[j]]=1;
			t++;
		}
		else{
			t--;
			while(x[t]!=a[j]){
				f[x[t]]=0;
				t--;
			}
			t++;
		}
	}
	for(int j=1;j<t;j++){
	s[x[j]]++;
	}
}
for(int i=1;i<=m;i++){
	cout<<s[i]<<" ";
}
	return 0;
}
