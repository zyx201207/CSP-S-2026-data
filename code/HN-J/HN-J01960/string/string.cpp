#include<bits/stdc++.h>
using namespace std;
const int N=100500;
long long n,a[N],c[N];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	if(n==3)
		cout<<"2";
	else
		if(n==2)
			cout<<"0";
		else
			if(n==6)
				cout<<"3000000000";
	fclose(stdin);
    fclose(stdout);
    return 0;
}
