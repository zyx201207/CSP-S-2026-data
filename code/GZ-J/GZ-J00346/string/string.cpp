//GZ-J00346ª∆≤≈ËÚ 
#include<iostream>
#include<string>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int n;
	cin>>n;
	
	string a = "";
	while(n--){
		int x;
		char op;
		cin>>x>>op;
		while(x--){
			a += op;
		}
	}
	
	int d = 0,len = a.size() - 1;
	
	for(int i = 0,j = len;i <= j;i++,j--){
		if(a[i] != a[j]) d ++;
	}
	
	cout<<d;
	return 0;
}
