#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c[500005],f[300005],r[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin>>c[i];	
	}
	int fc=0,t;
	for(int i=0;i<m;i++){
		for(int j=i;j<n;j++){
			/*for(int k=0;k<j;k++){
				if(f[k]==c[j]){
					fc = 0;
				} 
			}*/
			f[fc]=c[j]; 
			fc++;
		}
	}
	for(int i=0;i<n*m;i++){
		if(!f[i])break;
		r[f[i]]=f[i];
		cout << r[i]+1 << " ";
	}
	return 0;
}
