#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int mv = -1,a[500005],b[500005];
	long long n,m;
	cin >> n >> m;
	b[0] = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		b[i] = abs(a[i+1] - a[i]);
	}
	int v = 0;
	for(int i=0;i<n;i++){
		for(int j=i;;j++){
			v += b[j];
			if(v > m){
				if(mv < j - i + 1){
					mv = j - i + 1;
				}
				break;
			}
		}
	}
	cout << mv;
	return 0;
}
