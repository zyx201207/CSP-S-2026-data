#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],ch;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
        if(a[i] <= a[i - 1]){
        	ch = a[i];
        	a[i] = a[i - 1];
        	a[i - 1] = ch;
		}
	}
	for(int i = 1;i <= n;i++){ 
        if(a[i] <= a[i - 1]){
        	ch = a[i];
        	a[i] = a[i - 1];
        	a[i - 1] = ch;
		}
	}
    cout << a[m];
    return 0;
}
