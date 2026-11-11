#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;//B m sub sta,n sub way,
	cin >> c >> n >> m >> d >> q;
	int wm[50002];
	int sta2[50002];
	int sta[50002][2];
	int want[50002][2];
	
	for(int i=1;i<m;i++){
		cin >> wm[m];
	}
	
	
	for(int i=0;i<n;i++){
		cin >> sta2[i];
		for(int j=0;j<sta2[i];j++){
			cin >> sta[i][0];
			cin >> sta[i][1];
		}	
	}
	
	for(int i=1;i<q;i++){
		cin >> want[i][0];
		cin >> want[i][1];
	}
	
	for(int i=1;i<q;i++){
		int t;
		t= wm[want[i][0]] + sta[want[i][0]][1] + sta[want[i][1]][1] + wm[want[i][1]];
		for(int z=1;z<n;z++){
			for(int y=1;y<sta2[z];y++){
				for(int x=sta2[z];x>1;x--){
					if((sta[y][0]==want[i][0]) and (sta[y][1]==want[i][1])){
						cout << t;
					}
				}
			}
		}
	//
	//
	//
	//
	}
	fclose(stdin);
	fclose(stdout);
}
