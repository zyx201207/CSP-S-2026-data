#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int la=0;
	for(int i=n;i>=1;i--){
		if(a[i]==la){
			continue;
		}b[a[i]]+=i;
		la=a[i];
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}return 0;
} //csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//csp-j RP++
//CCF 求求这道题给我16分吧 
