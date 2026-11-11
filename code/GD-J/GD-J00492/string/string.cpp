#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
string ansp;
signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	if(n<=1){
		cout<<"0";
		return 0;
	}
	
	int ans=0;
	string lef;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ansp[j]=c[i];
			lef=ansp[j];
			//cout<<ansp[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int k=1;k<=m;k++){
			for(int j=m;j>=1;j--){
				if(ansp[k]==ansp[j]){
					cout<<ans;
					return 0;
				}
			}
		}
	}	
	return 0;
}
//3
//2 a
//2 b
//1 c
//NO~~~~
