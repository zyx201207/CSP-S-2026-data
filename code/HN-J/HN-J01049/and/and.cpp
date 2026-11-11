#include<bits/stdc++.h>
using namespace std;
int add(int a,int b){
	int w[200005],e[200005],q=0,l=0,h[200005],ans=0,r;
	while(a!=0){
		w[q]==a%2;
		a/=2;
		q++;
	}l=q;q=0;
	while(b!=0){
		e[q]==b%2;
		b/=2;
		q++;
	}r=min(l,q);
	for(int i=0;i<r;i++){
		
		if(w[i+l-r]==e[i+q-r])
		h[i]=0;
		else h[i]=1;
	}
	for(int i=r-1;i>=0;i--){
		ans+=pow(h[i],r-1-i);
	}
	return ans;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m,a[200005]={},maxn[200005]={},x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j]>maxn[i]){maxn[i]=a[j];x=j;
			}
		}a[x]=0;
	}
	x=maxn[0];
	for(int i=1;i<m;i++){
		x=add(x,maxn[i]);
	}
	cout<<x;
	return 0;
}//x

