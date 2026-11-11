#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],dd; 
bool f;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    	cin>>a[i];
    	t[a[i]]++;
    	if(t[a[i]]==n){
    		f=1;
    		dd=a[i];
		}
	}
	if(f){
		for(int i=1;i<=m;i++){
			if(i==dd){
				cout<<1<<" ";
			}else{
				cout<<0<<" ";
			}
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
    return 0;
}
