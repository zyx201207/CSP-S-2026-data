#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k;
	cin>>n>>m;
	int a[n],b[n],s[m]={};
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			b[j]=a[j];
		}
		for(j=i;j<n;j++){
			if(j!=i){
				int w=-1;
				for(k=i;k<j;k++){
					if(b[k]==b[j]){
						w=k;
						break;
					}
				}
				if(w!=-1){
					for(k=i;k<w;k++){
						b[k]=-1;
					}
				}
			}
		}
		for(j=i;j<n;j++){
			if(b[j]!=-1){
				s[b[j]]++;
			}
		}
	}
	for(i=0;i<m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
