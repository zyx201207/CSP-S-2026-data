#include<bits/stdc++.h>
using namespace std;
int n,a[200000+5],m,max1=-1,maxn=-1,px,kk;
void cou(int k,int num,int s){
	for(int i=num+1;i<=n;i++){
		if(k&a[i]<=max1) cou(k,num+1,s);
		else{
			if(s+1==m&&max1<k&a[i]){
				max1=k&a[i];
				cou(k,num+1,s);
			}
			else{
				if(k&a[i]>maxn) maxn=k&a[i],px=i;
				cou(k,num+1,s);
			}
		}
	}
	if(s!=m) cou(maxn,px,s+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=a[1];
	for(int i=1;i<=n;i++)
		cou(a[i],i,1);
	cout<<max1;
	return 0;
}
