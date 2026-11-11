#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdin);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int kt[m+10];
	int xltd[n+10][2*d+10];
	for(int i=1;i<=n;i++){
		cin>>kt[i];
	for(int i=1;i<=n;i++){
		cin>>xltd[i][1];
		for(int j=2;j<=2*xltd[i][1]+1;j++){
			cin>>xltd[i][j];
		}
	}
}
	int jh[q+10][3];
	for(int i=1;1<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>jh[i][j];
		}
	}
	for(int jhq=1;jhq<=q;jhq++){
		int t[100000];
		int num=0;
		for(int i=1;i<=xltd[1][1];i++){
			for(int j=1;j<=xltd[2][1];j++){
				if(xltd[1][2*i]==xltd[2][2*j]){
					for(int wj=1;wj<=xltd[2][1];wj++){
						for(int k=1;k<=xltd[3][1];k++){
							if(xltd[1][2*j]==xltd[3][2*k]){
								t[xltd[1][2*i]]=xltd[1][2*i+1]+xltd[2][2*j+1]+xltd[2][2*wj+1]+xltd[3][2*k+1];
								num++;
				}
			}
			}
		}
		}
	}
	sort(t,t+num);
	cout<<t[1]+kt[1]+xltd[1][jh[jhq][1]]+xltd[3][jh[jhq][2]]+kt[3];
}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
