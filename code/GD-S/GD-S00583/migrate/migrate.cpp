#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t,n;
long long posx[N],Delta=-1,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,Delta=-1;
		for(int i=1;i<=n;i++){
			cin>>posx[i];
			if(i>1&&Delta==-1)	Delta=posx[i]-posx[i-1];
			else if(i>1&&Delta!=-2&&Delta!=posx[i]-posx[i-1]){
				Delta=-2;
			}
		}
		if(Delta>0){
			d/=Delta;
			cout<<((d==2)*(n-3))<<endl;
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
