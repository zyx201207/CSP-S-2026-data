#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],p[200005],cnt[200005],t;
long long f(int y,int z){
	for(int j=z;j<t;j++){
		if(p[j]==y){
			return j;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		t=i;
		for(int j=i;j<n;j++){
			if(f(a[j],i)==-1){
				p[t]=a[j];
				t++;
			}else{
				t=f(a[j],i)+1;
			}
		}
		for(int j=1;j<=m;j++){
			if(f(j,i)!=-1){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
