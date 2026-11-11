#include <bits/stdc++.h>
using namespace std;
int c[10000];
int b[10000];
long long n;
long long m;
long long a;
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a;

	for(int i=1;i<n;i++){
		c[i]>>a;
		cin>>c[i];
		for(int j=1;j<n;j++){
			if(c[i]<c[i+1]){
				b[j]=c[i];
				b[j+1]=c[i+1];
			}else{
				b[j]=c[i+1];
				b[j+1]=c[i];
				}
				for(int k=1;k<n/2;k++){
					if(m>b[j+1]-b[j]){
						m=m-(j-1)*(b[j+1]-b[j]);
						ans++;
						if(b[1]==b[n]){
							break;
						}
					}
				}
		}
	}
	cout<<ans;
	return 0;
}
