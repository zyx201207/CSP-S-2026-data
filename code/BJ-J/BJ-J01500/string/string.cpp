#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
string l;
int m, ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        m += a[i];
        char s;
        cin >> s;
        for(int j = 1; j <= a[i]; j++) l = l + s;
    }
    int left = 0, right = m - 1;
    while(left < right){
        if(l[left] != l[right]) ans++;
        left++;right--;
    }
    printf("%d", ans);
	return 0;
}
