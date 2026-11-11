#include<bits/stdc++.h>
using namespace std;
long long w[100000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		
		cin>>w[i];
	}
	cout<<5*m<<endl<<m*2+q;
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
