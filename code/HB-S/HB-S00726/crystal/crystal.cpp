#include <bits/stdc++.h>
#define lol long long
using namespace std;
int N;lol M;
int ans=1,res=1;
lol pay=0;
lol a[500050];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++){cin>>a[i];}
	if(N==1){cout<<1<<'\n';return 0;}
	sort(a+1,a+1+N);
	int it=1;
	for(int i=2;i<=N;i++){
		pay+=(a[i]-a[i-1])*ans;ans++;
		while(pay>M){
			pay-=(a[i]-a[it]);
			it++;ans--;
		}
		res=max(ans,res);
	}
	cout<<res<<'\n';
	return 0;
}

/*
Sample Input 1
5 5
1 2 4 8 9

Sample Input 2
5 8
-3 -1 2 2 7 
*/