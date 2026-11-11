#include<bits/stdc++.h>
using namespace std;
int b[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m, s=0;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[n];
		b[i]=1;
	}
	for(int p=0;p<n;p++){
		for(int i=p;i<n;i++){
			int k=0;
			for(int j=p;j<i;j++){
				if(a[j]=a[i] && b[j]=1 || k==1){
					b[j]=0;
					k=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]=m && b[i]=1)s++;
		}
	}
	cout << s;
	return 0;
}
