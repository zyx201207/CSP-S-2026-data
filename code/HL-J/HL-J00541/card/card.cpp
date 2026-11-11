#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m>>a[0];
	int cnt=a[0];
	int la=a[0];
	int s=0;
	for(int i=1;i<n;i++){
		int t;cin>>t;
		if(t==la){
			cnt+=la;
		}
		else{
			a[s]=cnt;
			s++;
			la=t;
			cnt+=la;
		}
	}
	for(int i=0;i<s;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
