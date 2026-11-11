#include<bits/stdc++.h>
using namespace std;int a[1000000],b[1000000],bj[1000000],zl[1000000]={};
//HN-02278
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int f=0;f<n;f++){
		for(int s=0;s<n;s++){
			a[s]=b[s];
		}
		for(int z=0;z<m;z++){
			bj[z]=0;
		}
		for(int i=f;i<n;i++){
			while(a[i]==0){
				i++;
			}
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j]){
					for(int o=i;o<j;o++){
						a[o]=0;
					}
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(bj[a[i]]!=1){
				zl[a[i]]++;
				bj[a[i]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<zl[i]<<' ';
	}
	return 0;
}
