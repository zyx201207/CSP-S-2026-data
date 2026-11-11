#include <bits/stdc++.h>
using namespace std;
string q;
int w,e,cmp;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	char s;
    	int c;
    	cin>>c>>s;
    	for(int j=1;j<=c;j++){
    		q[w]=s;
    		w++;
    		e++;
		}
	}
	for(int i=0;i<e/2;i++){
		if(q[i]!=q[e-1-i]){
			cmp+=1;
		}
	}
	cout<<cmp;
    return 0;
}

