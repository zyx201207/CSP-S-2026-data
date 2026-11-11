#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,trip[114514][2],line[25][1919810];
struct station{
	int w,t,;
}s[1919810];
int main(){
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
		cin >> s[i].w;
    }	
    for(int i=1;i<=n;i++){
		int k,xb=1;
		cin >> k;
		for(int j=1;j<=k;j++){
			int number;
			cin >> number;
			cin >> s[number].t;
	    }	
    }	
    for(int i=1;i<=q;i++){
		cin >> trip[i][0] >> trip[i][1];
    }	
    for(int i=1;i<=m;i++){
		cout << s[i].w << ' ' << s[i].t << endl;
    }	
}
