#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m; 
long long a[N];
long long ans;
bool bj[N][31];
long long pow2[31];
int total[31];
int ansflag[31];
bool flag;
int tt;
int bj2[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pow2[0]=1;
	for(int i = 1;i<=30;i++){
		pow2[i]=pow2[i-1]*2;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		for(int j = 30;j>=0;j--){
			if(pow2[j]<=a[i]){
				a[i]-=pow2[j];
				bj[i][j]=true;
				total[j]++;
			}
		}
	}
	for(int i = 30;i>=0;i--){
//		cout<<i<<" "<<total[i]<<endl;
		if(total[i]>=m){
			flag=true;
			bj2[++tt]=i;
			for(int j = 1;j<=n;j++){
				bool hh=0;
				for(int k=1;k<=tt;k++){
					if(!bj[j][bj2[k]]) hh=true;
				}
				if(hh){
//					cout<<i<<" "<<j<<"¡¡";
					for(int k=0;k<=30;k++){
						if(bj[j][k]){
							bj[j][k]=0;
							total[k]--;
						}
					}
				}
				
					
			}
		}
	}
	for(int j = 1;j<=n;j++){
		bool hh=0;
		for(int k=1;k<=tt;k++){
			if(!bj[j][bj2[k]]) hh=true;
		}
		if(!hh){
			for(int k=0;k<=30;k++){
				if(bj[j][k]){
					ansflag[k]++;
				}
			}
		}
	}
	
	if(!flag) cout<<0;
	else{
		for(int i=0;i<=30;i++){
			if(ansflag[i]>=m){
				ans+=pow2[i];
			}
		}
		cout<<ans;
	}
	return 0;
}
