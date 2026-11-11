#include<bits/stdc++.h>
using namespace std;
int a[500005],d[500005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<'1';
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	int mx=1;
	for(int i=2;i<=n;i++){
		int j=i;
		int k=1;
		while(j>1&&(d[i]-d[j-2])>=(a[i]*(k+1)-m)){
			k+=1;
			j-=1;
		}
		mx=max(mx,k);
	}
	cout<<mx<<endl;
	return 0;
} 
