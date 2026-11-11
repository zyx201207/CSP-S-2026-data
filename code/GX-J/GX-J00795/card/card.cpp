#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream("card.in");
    ofstream("card.out");
    int n,m;
    int s[500000];
    cin>>n>>m;
    stack<int> a,b;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        a.push(s[i]);
    }
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=i;j++){
            a.push(s[j]);
        }
        for(int j=1;j<=i;j++){
            if(a.top())
            b.push(a.top());
        }
    }
	return 0;
}
