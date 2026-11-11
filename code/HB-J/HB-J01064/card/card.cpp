#include <bits/stdc++.h>
using namespace std;
const int MAXX=1000000+5;
int o[MAXX];
int ans[MAXX];
int c[MAXX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	int ans[m]={0};
	int o[n];
	int c[n];
	for(long long i=n-1;i>=0;i--){
		cin>>c[i];
	}
	long long xi=0;
	for(long long i=0;i<n;i++){
		o[xi]=c[i];
		
		for(long long p=0;p<xi-1;p++){
			if(o[p]==c[i]){
			xi=p;
			o[p]=c[i];
			break;
		}
		}
		for(long long p=0;p<xi;p++){
			ans[o[p]-1]++;		
		}
		xi++;
	}
	for(long long i=0;i<m;i++)
	cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
