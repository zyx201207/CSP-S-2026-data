#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long s,m;
    char b;
};
Node a[100009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long h = 0;
    int s1;
    cin >> s1;
    for(int i = 1;i <= s1;i++){
        cin >> a[i].s >> a[i].b;
        h += a[i].s;
    }
    long long ans = 0;
    long long l = 0,r = h + 1,l1 = 1,r1 = s1;
    int fl;
    if(h % 2 != 0){
		fl = h / 2 + 1;
	}
    while(l < r){
		if(h % 2 == 0){
            if(l + a[l1].s >= h + 1 && r - a[r1].s <= h || l == r - 1){
                break;
            }
        }
        else{
            if(l + a[l1].s >= fl && r - a[r1].s <= fl || l == r - 1){
                break;
            }
        }
        
        if(l < h - r + 1){
			//cout << 1 << endl;
            if(a[l1].b != a[r1].b){
				//cout << 4 << endl;
                ans += min(a[l1].s,h - r + 1 - l);
            }
            l1++;
            l += a[l1].s;
        }
        else if(l > h - r + 1){
			// << 2 << endl;
            if(a[l1-1].b != a[r1].b){
                ans += min(a[r1].s,l - h + r - 1);
            }
            r1--;
            r -= a[r1].s;
        }
        else if(l == h - r + 1){
			//cout << 3 << endl;
            if(a[l1].b != a[r1].b){
                ans += min(a[l1].s,a[r1].s);
            }
            if(a[l1].s < a[r1].s){
                l += a[l1].s;
                l1++;
            }
            else if(a[l1].s > a[r1].s){
                r -= a[r1].s;
                r1--;
            }
            else{
				l += a[l1].s;
                l1++;
                r -= a[r1].s;
                r1--;
			}	
        }
        //cout << ans << ' ' << l << ' ' << r << endl;
    }
    cout << ans;
    return 0;
}    
