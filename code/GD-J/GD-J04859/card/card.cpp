#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
unordered_map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int now[n+5]={0},len=0;
		for(int j=i;j<=n;j++){
			int pos=0,kl=0;
			bool ok=0;
			for(int k=n;k>=i;k--)
				if(a[k]==a[j])ok=1,pos=k;
			if(ok){
				for(int k=n;k>=pos;k--)now[k]=0,kl++;
				len-=kl;	
			}
			len++;
			now[len]=a[j];
			for(int k=n;k>=i;k--)mp[now[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[m]<<' ';
	}
	return 0;
}

