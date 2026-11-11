#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500025],b[500025],c[500025],i,j,k,f,ls[500025],max2=LONG_LONG_MIN,maxx=LONG_LONG_MIN,sum=0; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(i=1;i<n;i++){
		if(b[i]==b[i-1]){
			for(j=i-1;j>0;j--){
				if(b[i]==b[j]){
					ls[i]=i-j;
				}else{
					break;
				}
			}
		}
	}
	for(i=2;i<=n;i++){
		f=1;
		for(j=1;j<i;j++){
			sum=b[i]-b[j];
			if(sum<=m){
				c[f]=sum;
				c[f]+=c[f-1];
				f++;
			}
		}
		for(j=0;j<f-1;j++){
			for(k=j+1;k<f;k++){
				if(c[k]-c[j]>m)break;
				if(c[k]-c[j]>max2){
					max2=c[k]-c[j];
					maxx=max(maxx,k-j+1+ls[i+1]);
				}
			}	
		}
	}
	cout<<maxx;
	return 0;
} 
