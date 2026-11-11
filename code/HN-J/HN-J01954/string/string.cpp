#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0;
	char a[n+5][3];
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin >> a[i][j];
			if(a[j]=="a"){
				c++;
			}
		}
	}
	if(c<n){
		cout <<0;
	} 
	return 0;
}
