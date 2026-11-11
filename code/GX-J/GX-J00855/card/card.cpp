#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int p[9999],num[999][999];
	int t[999][999],flag[999][1]={0};
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[i][j]=p[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(flag[t[i][j]][0]){
				for(int k=1;k<=m;k++){
					flag[k][0]=0;
				}
				continue;
			}
			flag[t[i][j]][0]=1;
			num[t[i][j]][0]++;
		}
			for(int k=1;k<=m;k++){
				flag[k][0]=0;
			}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i][0]<<" ";
	}

	return 0;
}

