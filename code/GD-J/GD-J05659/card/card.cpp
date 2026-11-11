#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],x[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		string s;
		for(int i=j;i<=n;i++){
			char p=a[i]+48;
			if(s.find(p)!=-1){
				int x=s.find(p),len=s.size();
				s.erase(x,len);
			}
			s=s+p;
		}
		int l=s.size();
		for(int i=0;i<l;i++){
			x[int(s[i]-48)]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<x[i]<<" ";
}
