#include <bits/stdc++.h>
using namespace std;
long long n1[500005],n2[500005],m1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> n1[i];
	}
	for(int pp=1;pp<=n;pp++){
		for(int i=pp;i<=n;i++){
			int x=0;
			n2[i]=n1[i];
			for(int j=pp;j<=i;j++){
				if(x==1){
					n2[j]=0;
					continue;
				}
				if(n2[i]==n2[j]){
					x=1;
				}
			}
			
//			for(int i=1;i<=n;i++){
//					cout << n2[i] << " ";
//			}
//			cout << endl;
		}
		for(int l=1;l<=n;l++){
//			cout << n2[l] << endl;
			m1[n2[l]]++;
			n2[l]=0;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout << m1[i] << " ";
	}
	return 0;
}
