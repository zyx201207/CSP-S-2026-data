#include<iostream>
using namespace std;
const int Maxn=505;
int a[Maxn],desk[Maxn],End[Maxn][Maxn],ans[Maxn];
int n,m,pflag;
int lt,rt;
bool isps=false;
int main(){
	cin>>n>>m;
	lt=1,rt=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=lt;l<=rt;l++){
				if(desk[l]==a[i]){
					isps=true;
					pflag=i;
				}
			}
			if(isps){
				for(int l=pflag;l<rt;l++)desk[l]=0;
				rt=pflag;
				isps=false;
			}
			else {
				desk[rt]=a[i];
				rt++;
			}
		}
		for(int j=1;j<=rt;j++){
			End[i][j]=desk[j];
			if(desk[j]==i)ans[i]++;
			
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	return 0;
}
