#include <bits/stdc++.h>
using namespace std;
int q[20005];
int i;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(i=0;i<n;i++){
    	int w;
    	cin>>w;
    	q[i]=w;
	}
	sort(q,q+n);
	for(i=0;i<n;i++){
    	cout<<q[i]<<" ";
	}
	cout<<endl;
	cout<<q[n/2];
    return 0;
}

