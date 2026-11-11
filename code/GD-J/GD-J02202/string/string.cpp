#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int cnt;
	char c;
}a[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i].cnt);
		cin>>a[i].c;
	}
	long long i=1, j=n, now=0, ni=a[i].cnt, nj=a[j].cnt;
	while(i<=j){
		long long si=0, sj=0;
		si=ni-now;
		sj=nj-now;
		if(si>sj){
			if(a[i].c!=a[j].c){
				ans+=sj;
			}
			j--;
			now+=sj;
			nj+=a[j].cnt;
		}
		else if(si<sj){
			if(a[i].c!=a[j].c){
				ans+=si;
			}
			i++;
			now+=si;
			ni+=a[i].cnt;
		}
		else{
			if(a[i].c!=a[j].c){
				ans+=si;
			}
			i++;
			j--;
			now+=si;
			ni+=a[i].cnt;
			nj+=a[j].cnt;
		}
	}
	cout<<ans;
	return 0;
}
