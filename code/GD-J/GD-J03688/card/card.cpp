#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ovo[m+1]={0},v[m+1];
	for(int i=0;i<n;i++){
		int op[n+1];
		int k=1;
		for(int j=i;j<n;j++){
			if(a[j]!=0){
				for(int o=1;o<=k;o++){
					if(op[o]==a[j]){
					for(int zzz=o;zzz<=k;zzz++){
						op[zzz]=0;
					}
				}
				}
				op[k]=a[j];
				k++;
			}
		}
			for(int o=1;o<=m;o++){
				if(v[op[o]]<k||v[op[o]]>k)
				ovo[op[o]]++;
				v[op[o]]=k;
			}
	}
	for(int i=1;i<=m;i++)
	cout<<ovo[i]<<" ";
}
