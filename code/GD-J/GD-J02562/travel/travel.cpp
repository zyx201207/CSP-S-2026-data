#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int nc1 = 0,nc2 = 0,ns1 = 0,ns2 = 0;
    for(int i = 0; i < 2;i++){
        nc1 = nc1 * 10 + (c1[i] - '0');
    }
    for(int i = 0; i < 2;i++){
        nc2 = nc2 * 10 + (c2[i] - '0');
    }
    for(int i = 0; i < 2;i++){
        ns1 = ns1 * 10 + (s1[i] - '0');
    }
    for(int i = 0; i < 2;i++){
        ns2 = ns2 * 10 + (s2[i] - '0');
    }
    int a1 = s1[2] - 'A';
    int a2 = s2[2] - 'A';
    if(nc1 == nc2){
    	cout << 1;
    	if (ns1 == ns2){
    		cout << 1;
    		if(a1 == 0){
    			if (a2 == 1) cout << 11;
    			else if (a2 == 2) cout << 10;
    			else cout << 0 << 0;
			}else if (a1 == 1){
				if (a2 == 0 || a2 == 2) cout << 11;
				else cout << 0 << 0;
			}else if(a1 == 2){
    			if (a2 == 0) cout << 10;
    			else if (a2 == 1) cout << 11;
    			else cout << 0 << 0;
    		}else if(a1 == 3){
    			if (a2 == 4) cout << 11;
    			else cout << 0 << 0;
			}else if(a1 == 4){
    			if (a2 == 3) cout << 11;
    			else cout << 0 << 0;
			}
		}else cout << 0<<0<<0;
	}else cout << 0<<0<<0<<0;
	cout << '\n';
}
