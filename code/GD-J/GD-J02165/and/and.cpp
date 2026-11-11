#include<bits/stdc++.h>
using namespace std;
const int M=2e5+1;
int k[M];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int a,b;
    cin >> a >> b;
    for(int i=0;i<a;i++){
    	cin >> k[i];
	}
    sort(k,k+a);
    int m=k[a-1];
    for(int i=a-1;i>a-b-1;i--){
    	m=k[i] &= m;
	}cout << m;

}
