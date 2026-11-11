#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);

    int n , m , ans = 0 , s = 0 , m1 , d = 1;
    vector<long long> v , vs;
    long long a[500009] = {};
    cin >> n >> m;
    a[0] = -1000000000009;
    bool judgeA = true , judgeB = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != i){
            judgeA = false;
        }if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
            judgeB = false;
        }
        if(a[i] != a[i - 1]){
            v.push_back(a[i]);
            vs.push_back(d);
            d = 1;
        }else{
            d++;
        }
    }
    
    if(judgeA == true){
        int i = 1 , j = 0;
		while(m > 0){
			j++;
            m -= i;
            i++;
        }
        cout << j;
        return 0;
    }else if(judgeB == true){
        int i = 1 , j = 0;
        int nn = abs(a[2] - a[1]);
		while(m >= 0){
			j++;
            m -= i;
            i += n;
        }
        cout << j;
        return 0;
    }

    sort(v.begin() , v.end() , greater<int>());

    for(int t = 0;t < v.size();t++){
		//cout << v[t] << endl;
        ans = 1;
        m1 = m;
        for(int i = t + 1;i < v.size();i++){
            m1 -= v[t] - v[i];
            if(m1 >= 0){
                ans += vs[i];
				//cout << a[t] << " " << a[i] << " " << m1 << " " << ans << endl;
            }else{
                break;
            }
        }
        s = max(s , ans);
    }
    cout << s;
    
    return 0;
}
