#include <bits/stdc++.h>
using namespace std;

int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=0,j=0,p=0;
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
			for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
             int sum=1;
            if (a[j]==a[sum]){
            	a[j]=a[sum+1];
            	sum++;
			}
		if(a[j]==1){
			l++;
		}
		if(a[j]==2){
			m++;
		}
		if(a[j]==3){
			n++;
		}
		}
	}
}
	cout << l << ' ' << j << ' ' << p;
	return 0;
}
	
	
	
	
	
