#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501000],da=1,f,b[9999][9999],p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((j-i)+1>=da){
				for(int k=i;k<=j;k++){
					b[i][j]+=a[j]-a[k];
					if(m>b[i][j]){
						if((j-i)>=da) da=(j-i)+1;
					}
				}
			}
		}
	}
	cout<<da;
	
	
	
	
	return 0;
}
