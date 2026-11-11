#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,w=0;
	cin>>n>>m;
	int a[m+1]={},t[5]={};
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		t[(i%2)]=x;
		if(t[1-(i%2)]==x) continue;
		a[w]=x;
		w++;
	}
	int bb[m+1]={},qq[m+1]={},d[m+1]={};
	while(n--){
		int f[m+1]={},wz=0,wzz;
		for(int i=0;i<m;i++){
			if(a[i]==f[i]){
				for(int j=0;j<wz;j++){
					if(qq[j]==a[i]){
						for(int k=j;k<wz-1;k++){
							bb[k]=qq[j];
							qq[j]=0;
							wzz=wz;
						}
						wz=j;
					}
				}
			}
			qq[wz]=a[i];
			f[a[i]]=1;
		}
		for(int i=0;i<wz;i++){
			d[qq[i]]++;
		}
		for(int k=0;k<m;k++){
			if(qq[k]!=0){
				bb[wz+k]=qq[k];
				qq[k]=0;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
