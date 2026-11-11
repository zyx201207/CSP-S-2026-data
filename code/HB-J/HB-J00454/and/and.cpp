#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a,g=0;
	cin >> n >> m;
	int l[n];
	for(int i=0;i<n;i++){
		l[i] = 0;
	}
	for(int i=0;i<n;i++){
		cin >> l[i];
	}
	int l2[n];
	while(g>=n){
		for(int i=0;i<n;i++){
			a=1;
			for(int j=0;j<n;j++){
				if(l[i]<l[j]){
					a=0;
				}
			}
			if(a==1){
				l2[0]=l[i];
			}
		}
		g++;
	}
	for(int i=0;i<n;i++){
		cout << l2[i];
	}
	
	
	
	return 0;
}
