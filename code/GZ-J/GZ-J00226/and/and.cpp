//GZ-J00226 ·ëè÷ôË
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll> a;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
        a.push_back(-1);
        cin>>a[i];
	}
	sort(a.rbegin(),a.rend());
    cout<<a[m-1];
	return 0;
}
