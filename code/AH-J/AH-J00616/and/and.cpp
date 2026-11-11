#include<bits/stdc++.h>
using namespace std;
string smax(string x,string y){
	if(x.size() != y.size()){
		int xl,yl;
		xl = x.size();
		yl = y.size();
		if(x1 < y1){
			return y;
		}
		else{
			return x;
		}
	}
	else{
		for(int i = 0;i < x.size();i++){
			if(x[i] > y[i]){
				return x;
			}
			else if(y[i] > x[i]){
				return y;
			}
		}
		return x;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	string a[200000];
	char b[200000];
	string maxt; 
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		int s = 70; 
	}
	cout << 0;
	return 0;
} 





















