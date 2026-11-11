#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans,maxx=-1,cnt=-1;
long long a[N];
bool cmp(int a,int b){
	return a>b;
}
bool pdb(){
	bool f=0;
	for(int i=1;;i++){
		if(pow(2,i)>n) break;
		if(pow(2,i)==n){
			f=1;
			break;
		}
	}
	int cnt=0;
	if(f==1){
		for(int i=1;i<=n;i++){
			if(a[i]==i-1) cnt++;
		}
	}
	else return 0;
	if(cnt==n){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
	} 
	if(m==1){
		maxx=cnt;
	}
	else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		} 
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				maxx=max(ans,maxx);
			}
		} 
	}
	else if(pdb()) maxx=0;
	else{
		sort(a+1,a+1+n,cmp);
		maxx=a[m];
	}
	cout<<maxx;
	return 0;
}
