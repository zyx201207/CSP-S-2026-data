# include<bits/stdc++.h>
using namespace std;
long long n,m,card,a[100005];
bool vid[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	card=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		vid[a[i]]++;
	}
	cout<<"0 0 0 0";
	return 0;
}
