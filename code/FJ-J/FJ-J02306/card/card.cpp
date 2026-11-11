#include <bits/stdc++.h>
using namespace std;
int b[100000][12];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,q;
	cin >>n >>q;
	int a[n+1000];
	for(int i=1;i<=n;i++){
		cin >>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(b[a[j]][1]==0){
				b[a[j]][0]++;
				b[a[j]][1]=1;
			}
			if(a[j]==a[i]){
				break;
			}
		}
		for(int j=0;j<100000;j++){
			b[j][1]=0;
		}
	}
	for(int i=1;i<=q;i++){
		cout <<b[i][0] <<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
