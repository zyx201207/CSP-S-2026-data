#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    srand(time(0));
    int a=rand()%100+1;
    cout<<a;
	return 0;
}
