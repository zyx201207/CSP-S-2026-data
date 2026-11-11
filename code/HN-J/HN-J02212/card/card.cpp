#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+5;
int n,m,a[N],n1,ii=1;
map<int,int>mp,mm;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	n1=n;
	while(n1--){
		int st[N],tt=0,hh=0;
		
		for(int i=ii;i<=n;i++){
//			if(hh-tt>=0&&hh-tt<=n){
				tt=i;
				if(mp[a[i]]>1||a[i]==st[hh-i]){
					hh=1;
					st[hh]=a[i];
				}else{
					st[++hh]=a[i];
					mm[a[i]]++;
				}
				cout<<st[hh]<<" ";
//			}
			
		}ii++;
		cout<<'\n';
	}

	for(int i=1;i<=m;i++){
		cout<<mm[i]<<" ";
	}
	return 0;
}

