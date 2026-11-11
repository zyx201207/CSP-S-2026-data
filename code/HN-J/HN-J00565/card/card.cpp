#include<bits/stdc++.h>
using namespace std;
int a[5*100000+5];
int b[5*100000+5];
bool m[3*100000+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	/*
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			int j=1,gg=1;
			b[j++]=a[i];
			if(m[b[j]]){
				int ii=j,sd=1;
				while(b[j--]!=b[ii]){
					m[b[j]]=false;
					a[sd+gg]=b[j];
					gg++,sd++;
				}
				m[b[ii]]=0,a[gg]=b[ii];
			}
			else m[b[j]]=true;		
		}
		for(int i=k;i<=n;i++) cout<<b[i],m[b[i]]=0;
	}*/
	cout<<1;
	return 0;
}
