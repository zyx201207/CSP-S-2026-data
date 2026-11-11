#include<bits/stdc++.h>
using namespace std;
struct s{
	int n;
	char a;
}p[2000000];
int main(){
	
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    
    int num=n;
    for(int i=1;i<=n;i++){
		cin >> p[i].n >> p[i].a;
		if(i>1){
			if(p[i].a==p[i])
			num++;
			}
		}
    if(n==1){
		cout << 0;
	}else if(num==n){
		cout << 0;
    return 0;
}
