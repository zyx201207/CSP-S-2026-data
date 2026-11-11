#include<bits/stdc++.h>
using namespace std;
const int N=2000006;
int c,t;
int n,k;
int x[N];
int y[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c>>t;
	for(int i=1;i<=t;i++){
		cin >>n>>k;
		int num1=0,num2=0;
		for(int j=1;j<=n-1;j++){
			cin >>x[j]>>y[j];
			if(j%2==1)num1+=x[j];
			else num2+=x[j];
		}
		cout<<abs((num2-num1)/2)<<endl;
	}
	return 0;
}
/*0 2
 5 2
 1 2
 2 3
 3 4
 4 5
 10 3
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 3 8
 7 9
 9 10*/
//2026年10月31日于滨海 

