#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,b[N]={0},c[N],d[2];
struct A{
	int k,p;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		a[i].p=1;	
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	/*if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j].p==1){
					if(b[a[j].k]==0&&a[j].p==1){
						c[ans++]=a[j].k;
						b[a[j].k]++;
					}else{
						int m=a[j].k;
						while(c[ans]!=m){
							a[j].p=0;
							c[ans]=0;
							ans--;
						}
						b[a[j].k]=0;
					}
				}	
			}
			for(int i=1;i<=ans;i++){
				d[c[ans]]++;
			}
		}
	}
	for(int i=1;i<=2;i++){
		cout<<d[i]<<" ";
	}*/
    return 0;
}

