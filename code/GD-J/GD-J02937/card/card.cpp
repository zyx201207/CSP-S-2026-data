#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+100;
int a[N],n,m,ans[N],p[N];
int check(int k,int b){
	for(int i=1;i<=b;i++){
		if(p[i]==k)return 1;
	}
	return 0;
}
void walk(int l,int b){
	for(int i=l;i<=b;i++){
		p[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		int b=0;
		for(int i=1;i<=n;i++)p[i]=0;
		for(int i=x;i<=n;i++){
			if(check(a[i],b)==0){
				b++;
				p[b]=a[i];
			}
			else{
				for(int y=1;y<=b;y++){
					if(p[y]==a[i]){
						walk(y,b);
						b=y-1;
						break;
					}
				}
				b++;
				p[b]=a[i];
			}
		}
		for(int i=1;i<=b;i++){
			ans[p[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
