#include<bits/stdc++.h>
using namespace std;

int main(){
	freopeb("travel.in","r",stdin);
	freopeb("travel.out","w",stdout);
	int p[5] = {1,1,1,0,0};
	string a[5];
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	if(a[1] != a[3]){
		cout<<"0000"<<" ";
	}else{
		int x = int(a[2][1]-'0') + 10*(int(a[2][0]-'0'));
		int y = int(a[4][1]-'0') + 10*(int(a[4][0]-'0'));
		if(x!=y){
			cout<<"1000"<<" ";
		}else{
			int tx = int(a[2][2]-'A');
			int ty = int(a[4][2]-'A');
			if(p[tx]!=p[ty])cout<<"1100"<<" ";
			else if(tx+1 != ty&&ty+1 != tx){
				cout<<"1110"<<" ";
			}else{
				cout<<"1111"<<" ";
			}
		}
	}
	
}
