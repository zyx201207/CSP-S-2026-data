#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    int n,m;
    cin >> n >> m;
    int a[200005];
    for(int i=1;i<=n;i++){
    	cin >> a[i];
	}
	int zueda=0;
	for(int i=1;i<=n-m+1;i++){
		for(int j=i;j<=n-m+1;j++){
			int s=a[j];
			for(int q=1;q<m;q++){
				s=s&a[j+q];
			}
			zueda=max(zueda,s);
		}
	}
	cout << zueda;
    return 0;
}
