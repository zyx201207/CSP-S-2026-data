#include<bits/stdc++.h>
using namespace std;
int n;
struct strs{
	int ai;
	char c;
}a[200005];
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].ai>=a[r].ai){
			if(a[l].c!=a[r].c){
				ans+=a[r].ai;
			}
			a[l].ai-=a[r].ai;
			a[r].ai=0;
		}
		else{
			if(a[l].c!=a[r].c){
				ans+=a[l].ai; 
			}
			a[r].ai-=a[l].ai;
			a[l].ai=0;
		}
		if(a[r].ai==0) r--;
		if(a[l].ai==0) l++;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
