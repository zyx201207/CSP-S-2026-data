#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N], k[N], t[N][N], begin[N], end[N];
int w[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdin);
	int c, n, m, d, q , times;
	cin>>c>>n>>m>>d>>q;
	for(int i=0; i<m; i++){
		cin>>w[i];
	}
	for(int i=0; i<n; i++){
		cin>>k[i];
		for(int j=0; j<k[i]; j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0; i<q; i++){
		cin>>begin[i]>>end[i];
	}
	for(int p=0; p<q; p++){
		for(int i=0; i<w[p]; i++){
			for(int j=0; j<k[i]; j++){
				int f=a[i][j];
				if(i==0&&j==0){
					times+=t[i][j];
				}else{
					times+=w[a[i][j]]+t[i][j];
				}
				if(a[i][j]==end[i]){
					times-=(w[a[i][j]]+t[i][j]);
					cout<<times<<endl;
					p++;
				}
				if(i==q&&a[i][j]!=end[i]){
					i++, j=0;
					if(a[i][j]==f){
						j++;
					}else{
						j++;
						times-=(w[f]+t[i][j]);
					}
				}
			}
		}
	}
	
	return 0;
}
