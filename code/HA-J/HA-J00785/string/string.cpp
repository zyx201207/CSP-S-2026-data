#include<bits/stdc++.h>
using namespace std;
string a;
int b[100000001];
int sum = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
    	cin >>  a[i] >> b[i];
    	
    }
    for(int i = 0;i < n;i++){
    	for(int j = n-1;j >= 0;i--){
    		if(a[i] != a[j]){
    			sum += b[j];
    		}
    	}
    }
    cout << sum;
	return 0;
}
