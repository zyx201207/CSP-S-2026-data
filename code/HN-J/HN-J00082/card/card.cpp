#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    int n,m,j;
	cin >> n >> m;
	long long bb[300005];
	for(int i=0;i<n;i++){
		cin>>bb[i];
	}

	cout<<n/2+1<<n/2-1<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
