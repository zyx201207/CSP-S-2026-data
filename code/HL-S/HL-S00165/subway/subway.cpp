#include <bits/stdc++.h> 

using namespace std;

int number[1001];

int nu[1001];
 
int t[1001][1001];

struct y{
	int s;
	int e;
}x[1001];

int main(){
	int  c,n,m,d,q;

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin >>c>>n>>m>>d>>q;
	
	for (int i=0;i<m;i++){
		cin >>number[i];
	}
	
	int num;
	int z;
	for (int i=0;i<n;i++){
		cin >>num;
		for (int j=0;j<num;j++){
			cin >>z;
			cin >>t[z][i];
		}
	}
	
	for (int i=0;i<q;i++){
		cin >>x[i].s>>x[i].e;
		nu[i]=number[x[i].s]+number[x[i].e];
	}
	int minn1=1001,minn2=1001;
	int id1,id2;
	
	for (int i=0;i<q;i++){
		for (int j=x[i];j<n;j++){
			for (int k=x[i].s;k<x[i].e;k++){
				if(t[k][j]){
					for (int l=0;l<n;l++){
						t[k][j]=min(t[k][j]+t[k][n],t[k][j-1])
					}	
				}
			}
		}
		cout <<nu[i];
	}

	
	return 0;
};


