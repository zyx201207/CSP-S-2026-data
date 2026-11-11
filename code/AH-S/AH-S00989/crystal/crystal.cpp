#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],q,cnt=0,b[1000000];
bool cmp(int a,int b){
	return a<b;
}
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1,cmp);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int t=m;
		for(int j=1;j<=n;j++){
			while(b[i]==b[j]){
				if(t==0){
					break;
				}
				b[j]++;
				t-=1;
			}
			q++;
			if(t==0){
				break;
			}
		}
		if(q>cnt){
			cnt=q;
			q=0;
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i]; 
		}
	}
	cout<<q;
	return 0;
}
