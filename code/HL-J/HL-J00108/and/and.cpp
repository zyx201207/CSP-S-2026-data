#include <bits/stdc++.h>
using namespace std;
const long long N = 214748364;
int tree[N];
int n,m;
int last;
void add(int n)
{
    int idx = 1;
    string s = "";
    while(n)
    {
        if(n & 1) s = "1" + s;
        else s = "0" + s;
        n /= 2;
    }
    for (char i : s){
        int u = i - '0';
        idx = idx * 2 + u;
        tree[idx]++;
        last = max(last,idx);
    }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        int a;
        cin >> a;
        add(a);
    }
    int temp = 0;
    for (int i = last;i >= 1;i--){
        if(tree[i] >= m){
            temp = i;
            break;
        }
    }cout << temp;
    string s = "";
    while(temp)
    {
    	if(temp == 1) break;
        if(temp & 1) s = s + "1";
        else s = s + "0";
        temp /= 2;
    }cout << s << endl;
	int ans = 0;
    for (int i = 0;i < s.length();i++)
    {
    	ans = ans + pow(2,i) * (s[i] - '0');
	}cout << ans;
}
