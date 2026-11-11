#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10],b[10],h[10][10];
stack <int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	for(int o = 1;o<=n;o++){
	for(int i = o;i<=n;i++){
		h[o][b[i]]++;
		if(h[o][b[i]]==2){
			for(int j = 1;j<=i;j++){
				if(b[j]==b[i]){
					for(int k = j;k<=i;k++){
						h[o][b[k]]--;
					}
					j = 15;
				}
			}
		}
		//cout<<h[o][b[1]]<<h[o][b[2]]<<h[o][b[3]];
	}
	}
	for(int i = 1;i<=m;i++){
		int sum = 0;
		for(int j = 1;j<=n;j++){
			sum+=h[j][b[i]];
		}
		if(i<m)
			cout<<sum<<" ";
		if(i==m)
			cout<<sum;
	}
	return 0;
}
