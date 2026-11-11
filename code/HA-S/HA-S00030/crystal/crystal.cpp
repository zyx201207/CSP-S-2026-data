#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=(int)n/2;i++){
		sum+=a[i];
	}

	for(int j=(int)n/2;j<n;j++){
		if(a[j+1]==a[j]){
			sum+=a[j+1];
		}
		else {
			break;
		}
	}
	sum+=m;
	int cnt=sum/a[(int)n/2];
	cout<<cnt;
	return 0;
}

