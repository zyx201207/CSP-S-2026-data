#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
void f(int n,int i){
	int l=i,r;
	for(r=i;r<=n;){
		r++;
		if(a[r]==a[l]){
			l=r;
		}
	}
	for(int i=l;i<=r;i++){
		b[a[i]]++;
	}
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f(n,i);
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
}
