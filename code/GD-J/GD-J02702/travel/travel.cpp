#include<bits/stdc++.h>
using namespace std;
char c[9][20];
int a[9],b[9];
bool ans[9];

int f(int x){
	return b[x]<4;
	
}


int main(){
	
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c[1]>>c[2]>>c[3]>>c[4];
	for(int i=1;i<5;i++){
		a[i]=c[i][0]*10+c[i][1];
		b[i]=c[i][2]-64;
	}
	if(a[1]==a[3]){
		ans[1]=1;
		if(a[2]==a[4]){
			ans[2]=1;
			if(f(2)==f(4)){
				ans[3]=1;
				if(b[2]==2 || b[4]==2 || b[2]==4 || b[4]==4){
					ans[4]=1;
				}
			}
		}
	}
	
	
	
	for(int i=1;i<5;i++){
		cout << ans[i];
	}
	return 0;
} 

