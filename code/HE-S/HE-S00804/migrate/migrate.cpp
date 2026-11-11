#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d,a[N];
bool fly(int x,int y){
	bool st=0;
	if (x<3) return 0;
	for (int i=x;i<=y;i++){
		if (a[i]-a[i-2]<=d && a[i-1]-a[i-3]<=d && st==0){
			if (st){
				return 0;
			}
			st=1;
		}
	}
	if (st) return 1;
	else return 0;
}
int main(){
	int C,T;
	cin>>C>>T;
	while (T--){
		cin>>n>>d;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		int res=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				if (fly(i,j)) res++;
			}
		}
		cout<<res+1<<endl;
	}
	return 0;
}

