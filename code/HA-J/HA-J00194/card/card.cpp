#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a[n],p[n];
	int b[m];
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int l=0;l<=n-1;l++){
		for(int i=0;i<=n-1;i++){
			p[p.size()]=a[i];
			for(int j=p.size-2;j>=0;j--){
				if(p[j]==p[p.size()-1]){
					string t[n];
					for(int k=0;k<=p.size-1;k++){
						if(!t>=j||!t<p.size()-1){
							t[t.size()]=p[k];
						}
					}
					p=t;
				}
			}
		}
		a=a-a[a.size-1];
	}
	return 0;
}
