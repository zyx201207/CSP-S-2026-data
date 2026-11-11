#include<bits/stdc++.h>
using namespace std;
int n,m;int cntt=0;
int lll[200005];
int smsm=0;//freopen("travel.out","w",stdout);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=0;i<n;i++)
    {
	    cin>>lll[i];
	    
	}
	sort(lll,lll+n);
	cntt=lll[n-1];
	for(int i=n-1;i>n-1-m;i--){
	    cntt=cntt&lll[i];
	}
	cout<<cntt;
	return 0;
}//不会做QWQ只能乱做了 
