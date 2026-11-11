#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500100],b[500100],h[500100],hx[300100];
unordered_map<int,int>s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n-i+1];
		b[n-i+1]=i;
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//	cout<<endl;
//	for(int i=n;i>0;i--)b[i]-=b[i+1];
	int p;
	for(int i=1;i<=n;i++){
		if(s.count(a[i])){
			for(int x=s[a[i]]+1;x<=i;x++)b[x]--;
			p=s[a[i]]-1;
			while(p>0){
				if(s[a[p]]!=p){
					for(int x=s[a[p]]+1;x<=p;x++)b[x]--;
					p=s[a[p]]-1;
				}else p--;
			}
		}else{
			p=i-1;
			while(p>0){
				if(s[a[p]]!=p){
					for(int x=s[a[p]]+1;x<=p;x++)b[x]--;
					p=s[a[p]]-1;
				}else p--;
			}
			s[a[i]]=i;
		}
//		for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//		cout<<endl;
	}
	for(int i=n;i>0;i--){
		
		if(b[i]>0){
			hx[a[i]]=b[i];
		}
	}
	for(int i=1;i<=m;i++)cout<<hx[i]<<" ";
	
	
	return 0;
} 
