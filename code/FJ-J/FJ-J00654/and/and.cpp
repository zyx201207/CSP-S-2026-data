#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	int x;
	for(int i = 0;i<n;i++){
		cin >> x;
	}
	cout << x;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
