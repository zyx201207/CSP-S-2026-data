#include<bits/stdc++.h>
using namespace std;
int c[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout); 
    int a,b,ans=2e20-1;
    cin>>a>>b;
    for(int i=0;i<a;i++){
    cin>>c[i];
	}
	sort(c,c+a);
	for(int i=0;i<b;i++){
    ans&=c[a-1];
    a--;
	}
	cout<<ans;
	return 0;
} 
