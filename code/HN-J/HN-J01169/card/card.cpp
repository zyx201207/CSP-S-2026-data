#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],b[10000]={0},s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool jd=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			for(int h=0;h<j;h++){
				if(b[h]==a[j]){
					jd=1;
					s=h;
					break;
				}
			}
			if(jd) for(int h=s;h<j;i++) b[h]=0;
			else b[j]=a[j];
		}
		for(int h=0;h<n-i;h++) if(b[h]==i) cout<<i;
	}
	return 0;
}  
