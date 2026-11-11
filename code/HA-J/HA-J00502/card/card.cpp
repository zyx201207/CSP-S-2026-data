#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=1;
	while(f<=m){
		int sum=0;
		for(int i=1;i<=n;i++){
			string s="";
			for(int j=i;j<=n;j++){
				if(s.find(a[i]+'0')==-1){
					s+=(a[i]+'0');
				}
				else {
					int v=s.find(a[i]+'0');
					s.erase(v,s.size()-1);
					s+=(a[i]+'0');
				}
			}
			if(s.find(f+'0')!=-1){
				sum++;
			}
		}
		cout<<sum<<" ";
	}
	return 0;
}
