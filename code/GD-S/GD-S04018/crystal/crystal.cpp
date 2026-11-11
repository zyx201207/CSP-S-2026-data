#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
//	for(int i=0;i<n;i++)cout<<a[i]<<' ';
//	cout<<endl;
	int w=0;
	while(m>0&&w<n-1){
		int need=abs(a[w+1]-a[w]);
		if(w!=0)need*=(w+1);
//		if(need!=0)cout<<w<<' '<<need<<' '<<m<<' '<<a[w]<<' '<<a[w+1]<<endl;
		if(need<=m){
			m-=need;
			a[w]+=need;
			w++;
		}else break;
	}
//	for(int i=0;i<n;i++)cout<<a[i]<<' ';
//	cout<<endl;
//	cout<<w;
	for(int i=w+1;;i++){
		if(a[w]!=a[i]||i==n){
			w=i;
			break;
		}
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
