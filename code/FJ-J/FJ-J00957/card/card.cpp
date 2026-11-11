#include<bits/stdc++.h>
using namespace std;
int m[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int n[a];
	for(int i=0;i<a;i++)cin>>n[i];
	for(int i=0;i<a;i++){
		int k[a],p=0;
		for(int j=i;j<a;j++){
			for(int l=0;l<p;l++){
				if(k[l]==n[j]){
					for(int ll=l;ll<p;ll++)k[ll]=0;
					p=l;
				}
			}
			k[p]=n[j];
			p++;
		}
		for(int i=0;i<p;i++)m[k[i]-1]++;
	}
	for(int i=0;i<b;i++)cout<<m[i]<<" ";
	return 0;
}
