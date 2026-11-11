#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cout<<3<<1<<4<<endl;
	struct cards[n-1];
	for(int f=0;f<n;f++) {
		cin>>cards[f];
	}
	int done[n-1];
	int d[n-1];
	for(int t=0;t<n;t++){
		for(int m=0;m<n-t;m++){
			if(cards[m]==done){
				for(int r;r<m;r++)
				break done[r];
			}
			done[m]=cards[m];
			
		}
		d[m]++;
	}
	for(int o=0;o<n;o++){
		cout<<d[o]<<endl;
	}
	return 0;
