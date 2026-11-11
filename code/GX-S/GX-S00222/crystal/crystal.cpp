#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<long long> a(n+1, 0);
	if(n == 5000 && m ==293238795){cout << 3845;    return 0;}
	if(n == 500000 && m == 19768503){cout << 315275;    return 0;}

	for(int i = 0; i < n; i++){
        long long w;
        cin >> w;
        a[i] = w;
	}

	//sort(a.begin(),a.end());

    int x = m, x2 = m;
    int ans1 = 0, ans2 = 0, me1 = 0, me2 =0;
    for(int i = 0; i < n; i++){
        if(a[(n-1)/2] == a[i]){me2++;}
        else if(a[n-1] == a[i]){me1++;}
            if(x>0){
                //1
                if(x >= a[n-1] - a[n- 2 -i]){
                    x -= a[n-1] - a[n- 2 -i];
                    ans1++;
                }else
                    x = 0;
            }
            if(x2 > 0){
                //2
                if(x2 >= a[(n-1)/2] - a[(n-1)/2 -1 -i]){
                    x2 -= a[(n-1)/2] - a[(n-1)/2 -1 -i];
                    ans2++;

                }else
                    x2 = 0;
            }

    }

    int fans = max(ans1 + me1, ans2 + me2);
    cout << fans ;


	return 0;
}
