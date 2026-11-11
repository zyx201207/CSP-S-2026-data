#include<bits/stdc++.h>
using namespace std;
int n, m, a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a, a+n);
		cout<<a[n-1];
	}
	int maxn=0;
	while(m >= 2){
		int maxn=INT_MIN, maxpos1=0, maxpos2=0;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(a[i] & a[j] > maxn){
					maxn = a[i] & a[j];
					maxpos1=i;
					maxpos2=j;
				}
			}
		}
		a[maxpos1]=maxn;
		a[maxpos2]=0;
		m--;
	}
	sort(a, a+n);
	cout<<a[n-1];
	return 0;
}
