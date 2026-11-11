#include<bits/stdc++.h>
using namespace std;
int n,k,x,a[200005],l,b[200005],m;
bool cmp(int a,int b){return b==0;}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],m=max(m,a[i]);	
	for(int i=1;i<=n;i++){
		l=n;
		for(int j=i;j<=n;j++){
			if(a[j]==k){
				for(int ji=j;ji<=n;ji++)a[ji]=0,l--;
				sort(a+1,a+1+n,cmp);
				break;
			}
			b[a[j]]++;
			for(int ji=i;ji<=j;ji++){
				if(a[ji]==a[j]){
					a[ji]=0;l--;
					sort(a+1,a+1+n,cmp);
				}
			}
		}
		n=l;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
