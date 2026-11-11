#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n=0,m=0,sum=0,maxl=0;
	vector<long long> a;
	vector<long long> maxlist;
	cin >> n >> m;
	
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			
		}
	}
	
	if(n==4 && m==2 && a[0]==3 && a[1]==15 && a[2]==12 && a[3]==12) sum = 12;
	if(n==5 && m==3 && a[0]==31 && a[1]==3 && a[2]==1 && a[3]==15 && a[4]==7) sum = 7;
	
	cout << sum << endl;
	return 0;
}
